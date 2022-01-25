import sys
x,y,w,h = map(int,sys.stdin.readline().rstrip().split())
Xdistance, Ydistance = w-x, h-y
if Xdistance >= x: xmin = x
else: xmin = Xdistance
if Ydistance >= y: ymin = y
else: ymin = Ydistance
if xmin>ymin: print(ymin)
else: print(xmin)