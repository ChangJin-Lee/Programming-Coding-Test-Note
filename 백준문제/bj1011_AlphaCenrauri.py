# 1+2+...+n+n-1+...+2+1 = n^2 임을 이용하는 문제.
import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    cnt=0
    x,y = map(int,sys.stdin.readline().rstrip().split())
    n = int((y-x)**0.5)
<<<<<<< HEAD
    # print(n)
    cnt+=2*n-1
    # print(cnt)
    square=n**2
    # print(square)
    if y-x-square > 0:
        if int((y-x-square)/n) == 0 : cnt+=1
        else: cnt+= int((y-x-square)/n)+1
=======
    cnt+=2*n-1
    square=n**2
    cnt+= int((y-x-square)/n)
    if (y-x-square)%n != 0 : cnt+=1
>>>>>>> 2bd9f5de8a960d3b49e39b230cbc244382b01101
    print(cnt)

# 숏코딩
# for i in[int]*int(input()):x,y=input().split();print(i(2*(i(y)-i(x)-.5)**.5))