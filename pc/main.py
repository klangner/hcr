import serial
import time


def main():
    reset()
    hcr = openConnection()
    count = 0
    step = 1;
    while True:
        line = hcr.readline()
        if len(line) > 0:
            print(str(time.time()) + ": " + line)
            count += step
            if abs(count) > 255:
                step = -step
            motors = "%d %d\n" % (count, count)
            print("Python: " + motors)
            hcr.write(motors)

def openConnection():
    return serial.Serial('/dev/ttyACM0', 57600, timeout=1)

def reset():
    ser = serial.Serial('/dev/ttyACM0', 1200)
    ser.setRTS(True)  # RTS line needs to be held high and DTR low
    ser.setDTR(False) # (see Arduino IDE source code)
    ser.close()
    time.sleep(1)

# Start script
main()
