import serial
import subprocess
import time

# Replace 'COM3' with your Arduino's actual port (e.g., '/dev/ttyUSB0' on Mac/Linux)
arduino_port = "COM3" 
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2) # Allow connection to settle

print(f"Listening on {arduino_port}...")

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        if line:
            print(f"Read from Arduino: {line}")
            
            # Option A: Run PHP directly via Command Line (No network/IP required)
            # Make sure 'php' is added to your computer's environment variables path
            subprocess.run(["php", "C:/xampp/htdocs/your_folder/receive.php", line])
            
            # Alternatively, if XAMPP Apache is running, you can hit localhost:
            # requests.get(f"http://localhost/your_folder/receive.php?data={line}")