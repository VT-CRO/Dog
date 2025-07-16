import serial
import time

# ---- Config ----
SERIAL_PORT = '/dev/ttyAMA0'  # adjust if using different port
BAUD_RATE = 115200
NUM_SERVOS = 12

# ---- Offsets from Arduino code ----
servo_offsets = [
    115, 90, 125,     # FR: Lower, Upper, Hip
    90, 30, 90,       # FL: Lower, Upper, Hip
    50, 70, 90,       # RR: Lower, Upper, Hip
    80, 180, 82       # RL: Lower, Upper, Hip
]

# ---- Serial Init ----
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # wait for Arduino reset

# ---- Current Angle Buffer ----
servo_angles = servo_offsets.copy()

def send_all_servos():
    """
    Sends current servo_angles to all 12 servos.
    """
    packet = bytearray([0xFF] + servo_angles)
    ser.write(packet)
    print("Initialized all servos to offset positions:")
    for i, a in enumerate(servo_angles):
        print(f"  Servo {i} => {a}°")

def send_servo_update(index, value):
    """
    Updates just one servo in the angle buffer and sends full packet.
    """
    servo_angles[index] = value
    packet = bytearray([0xFF] + servo_angles)
    ser.write(packet)
    print(f"Sent Servo {index} => {value}°")

def interactive_loop():
    print("\nEnter servo updates. Example: '3 90' sets Servo 3 to 90°.")
    print("Type 'exit' to quit.\n")

    while True:
        user_input = input("Servo#:Angle > ").strip().lower()
        if user_input in ['exit', 'quit']:
            break
        try:
            idx_str, val_str = user_input.split()
            idx = int(idx_str)
            val = int(val_str)
            if not (0 <= idx < NUM_SERVOS):
                print(f"Invalid servo index (0–{NUM_SERVOS - 1})")
                continue
            send_servo_update(idx, val)
        except ValueError:
            print("Invalid format. Use: servo_index angle (e.g., '5 120')")

try:
    send_all_servos()  # 🟢 Initialize servos to offset values
    interactive_loop()
except KeyboardInterrupt:
    print("\nExiting...")
finally:
    ser.close()
