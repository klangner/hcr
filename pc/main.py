import serial
import time
import math

ENCODER_RES     = 64        # ticks per rotation
WHEEL_BASE      = 0.285     # meters
WHEEL_PERIMETER = 0.424     # meters

class RobotState:
    def __init__(self, x, y, dir):
        self.x = x;
        self.y = y
        self.dir = dir

    def toString(self):
        return "(%.2f,%.2f), dir=%.2f" % (self.x, self.y, self.dir)

    def updateState(self, ticksLeft, ticksRight):
        dl = (ticksLeft * WHEEL_PERIMETER)/ENCODER_RES
        dr = (ticksRight * WHEEL_PERIMETER)/ENCODER_RES
        d = (dl+dr)/2
        x1 = self.x + d*math.cos(self.dir)
        y1 = self.y + d*math.sin(self.dir)
        dir = self.dir + (dr-dl)/WHEEL_BASE
        dir1 = math.atan2(math.sin(dir), math.cos(dir))
        return RobotState(x1, y1, dir1)


def main():
    reset()
    hcr = openConnection()
    count = 0
    step = 1;
    state = RobotState(0, 0, 0)
    while True:
        line = hcr.readline()
        if len(line) > 0:
            (l,r) = parseState(line)
            state = state.updateState(l, r)
            print(str(time.time()) + ": " + state.toString())
            count += step
            if abs(count) > 255:
                break
            hcr.write("%d %d\n" % (count, count))

def parseState(line):
    ns = line.strip()[1:-1].split(",")
    if len(ns) == 2:
        return (int(ns[0]), int(ns[1]))
    return (0,0)

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
