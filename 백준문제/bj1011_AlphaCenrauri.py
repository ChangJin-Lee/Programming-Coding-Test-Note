import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    cnt=0
    x,y = map(int,sys.stdin.readline().rstrip().split())
    n = int((y-x)**0.5)
    cnt+=2*n+1
    square=n**2
    cnt+= int((y-square)/n)
    if (y-square)%n != 0 : cnt+=1
    print(cnt)
