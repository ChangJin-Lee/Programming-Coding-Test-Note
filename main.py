import sys
input = list(map(int,sys.stdin.readline().rstrip()))
print(input)
#bj10250 acm호텔
import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    H, W, N = map(int,sys.stdin.readline().rstrip().split())
    floor = N%H
    unit = N//H + 1 
    if floor == 0:
        floor = H
        unit = N//H # unit = 1 로 생각했음
    print(floor*100+unit)

# 숏코딩
# exec('h,w,n=map(int,input().split());n-=1;print((n%h+1)*100+n//h+1);'*int(input()))