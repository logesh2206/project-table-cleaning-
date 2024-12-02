import serial
import time

# Set up the serial connection (COM port and baud rate)
ser = serial.Serial('COM7', 9600)  # Replace 'COM3' with the correct port
time.sleep(2)  # Wait for the connection to establish

# Open a file to log data with UTF-8 encoding
with open("data.csv", "w", encoding="utf-8") as f:
    while True:
        try:
            # Read and decode the data from Arduino
            sensor_data = ser.readline().decode('utf-8', errors='ignore').strip()
            print(sensor_data)  # Print data in the terminal
            f.seek(0)  # Move the file pointer to the beginning of the file
            f.write(sensor_data + "\n")  # Write data to file with a newline
            f.truncate()  # Truncate the file to the current position
            f.flush()  # Flush the file buffer to ensure data is written immediately
            time.sleep(1)  # Wait for 1 second before reading the next line
        except KeyboardInterrupt:
            print("Logging stopped.")
            break

ser.close()