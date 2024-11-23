import serial
import time

# Set up the serial connection (COM port and baud rate)
ser = serial.Serial('COM3', 9600)  # Replace 'COM3' with the correct port
time.sleep(2)  # Wait for the connection to establish

# Open a file to log data
with open("sensor_data.csv", "w") as f:
    while True:
        try:
            # Read and decode the data from Arduino
            sensor_data = ser.readline().decode().strip()
            print(sensor_data)  # Print data in the terminal
            f.write(sensor_data + "\n")  # Write data to file with a newline
        except KeyboardInterrupt:
            print("Logging stopped.")
            break

ser.close()
