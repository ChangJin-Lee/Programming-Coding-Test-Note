# when we representing value of pi, use math module
import sys, math
R = int(sys.stdin.readline().rstrip())
print("%0.6f\n%0.6f" % ((math.pi*(R**2),2*(R**2))))