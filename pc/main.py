import serial
import time


def main():
    romeo = serial.Serial('/dev/ttyACM0', 57600, timeout=1)
    count = 0
    step = 1;
    while True:
        line = romeo.readline()
        if len(line) > 0:
            print(str(time.time()) + ": " + line)
            count += step
            if abs(count) > 255:
                step = -step
            motors = "%d %d\n" % (count, count)
            print("Python: " + motors)
            romeo.write(motors)


main()
