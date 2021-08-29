import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    cnt=0
    x,y = map(int,sys.stdin.readline().rstrip().split())
    n = int((y-x)**0.5)
    # print(n)
    cnt+=2*n-1
    # print(cnt)
    square=n**2
    # print(square)
    if y-x-square > 0:
        if int((y-x-square)/n) == 0 : cnt+=1
        else: cnt+= int((y-x-square)/n)+1
    print(cnt)
