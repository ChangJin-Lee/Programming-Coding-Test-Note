import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    x1,y1,r1,x2,y2,r2 = map(int,sys.stdin.readline().rstrip().split())
    # (-2*x1+2*x2)*X+(-2*y1+2*y2)*y+x1**2+y1**2-x2**2-y2**2=r1**2-r2**2
    y=0
    x = (r1**2-r2**2-((-2*y1+2*y2)*y+x1**2+y1**2-x2**2-y2**2))/(-2*x1+2*x2)