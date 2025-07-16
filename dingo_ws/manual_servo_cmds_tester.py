import serial
import time

# Open serial connection to Arduino
ser = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)
time.sleep(2)  # give time for Arduino reset

# Create packet: 0xFF header + 12 zero-angle values
packet = bytearray([0xFF] + [0] * 12)

# Send the packet
ser.write(packet)
print("Sent: all servos to 0°")

# Optional: keep the connection alive briefly
time.sleep(1)
ser.close()
