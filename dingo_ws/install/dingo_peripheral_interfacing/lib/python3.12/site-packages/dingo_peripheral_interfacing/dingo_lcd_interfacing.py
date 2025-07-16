#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import spidev as SPI
from dingo_peripheral_interfacing import LCD_1inch47
from PIL import Image, ImageDraw, ImageFont
import os
import socket
import time
from dingo_msgs.msg import ElectricalMeasurements

import platform

ON_PI = os.uname().machine.startswith('arm')

if ON_PI:
    from dingo_peripheral_interfacing import LCD_1inch47

class DingoDisplayNode(Node):
    def __init__(self):
        super().__init__('dingo_display_node')

        self.timer_period = 0.02  # 50 Hz
        self.timer = self.create_timer(self.timer_period, self.run)

        self.ssid = ''
        self.ipAddress = ''

        self.battery_percentage = 0.7

        if ON_PI:
            self.disp = LCD_1inch47.LCD_1inch47()
            self.disp.Init()
            self.disp.clear()
        else:
            self.disp = None
            self.get_logger().info("LCD skipped: Not on Pi")

        self.subscription = self.create_subscription(
            ElectricalMeasurements,
            '/electrical_measurements',
            self.update_battery_percentage,
            10
        )

        self.get_logger().info("Dingo LCD Display Node started.")
    
    def update_battery_percentage(self, msg):
        max_voltage = 16.8
        min_voltage = 14.0
        battery_voltage = max(min(msg.battery_voltage_level, max_voltage), min_voltage)
        self.battery_percentage = (battery_voltage - min_voltage) / (max_voltage - min_voltage)

    def run(self):
        if self.disp is None:
            return  # Nothing to do
        try:
            image1 = Image.new("RGB", (self.disp.height, self.disp.width), "black")
            draw = ImageDraw.Draw(image1)

            # Load fonts
            Font1 = ImageFont.truetype("/usr/share/fonts/truetype/Font02.ttf", 25)
            Font1_small = ImageFont.truetype("/usr/share/fonts/truetype/Font02.ttf", 20)
            Font1_large = ImageFont.truetype("/usr/share/fonts/truetype/Font02.ttf", 60)

            draw.text((20, 110), 'SSID: ' + self.ssid, fill="WHITE", font=Font1)
            draw.text((20, 135), 'IP: ' + self.ipAddress, fill="WHITE", font=Font1)
            current_time = time.strftime("%I:%M:%S%p")
            draw.text((220, 0), current_time, fill="WHITE", font=Font1_small)

            # Battery status bar
            batt_status = Image.open(
                os.path.join(
                    self.get_package_share_directory('dingo_peripheral_interfacing'),
                    'lib', 'emptybatterystatus_white.png'
                )
            )
            batt_draw = ImageDraw.Draw(batt_status)

            if self.battery_percentage <= 0.20:
                batt_fill = "RED"
            elif self.battery_percentage <= 0.60:
                batt_fill = "#d49b00"  # yellow
            else:
                batt_fill = "#09ab00"  # green

            batt_draw.rounded_rectangle(
                [(42, 92), (42 + (153 * self.battery_percentage), 170)],
                8,
                fill=batt_fill
            )
            batt_draw.text(
                (68, 95),
                str(int(self.battery_percentage * 100)) + "%",
                fill="WHITE",
                font=Font1_large
            )

            batt_scale_factor = 0.8
            resized_batt_status = batt_status.resize(
                (
                    int(batt_status.size[0] * batt_scale_factor),
                    int(batt_status.size[1] * batt_scale_factor)
                )
            )

            image1.paste(resized_batt_status, (62, -40), resized_batt_status.convert('RGBA'))

            image1 = image1.rotate(0)
            image1 = image1.transpose(Image.ROTATE_270)
            self.disp.ShowImage(image1)

            # Update SSID and IP on each loop
            try:
                self.ssid = os.popen("iwgetid -r").read().strip()
            except Exception as e:
                self.get_logger().error(str(e))
                self.ssid = "N/A"

            try:
                hostname = socket.gethostname()
                self.ipAddress = socket.gethostbyname(hostname)
            except Exception as e:
                self.get_logger().error(str(e))
                self.ipAddress = "-.-.-.-"

        except Exception as e:
            self.get_logger().error(str(e))


def main(args=None):
    rclpy.init(args=args)
    node = DingoDisplayNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down LCD node.')
    finally:
        node.disp.clear()
        node.disp.module_exit()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
