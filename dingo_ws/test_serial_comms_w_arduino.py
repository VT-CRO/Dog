import serial
import time

ser = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)  # Or '/dev/serial0' based on your Pi model

message_interval = 2  # seconds between sending messages
last_sent_time = time.time()

while True:
    # Check if it's time to send a message
    if time.time() - last_sent_time > message_interval:
        outgoing = "Hello from Raspberry Pi!"
        ser.write((outgoing + "\n").encode('utf-8'))
        print("Sent to Teensy:", outgoing)
        last_sent_time = time.time()

    # Check if Teensy responded
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print("From Teensy:", line)
