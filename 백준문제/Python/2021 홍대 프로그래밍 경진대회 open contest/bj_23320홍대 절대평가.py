import sys
N = int(sys.stdin.readline())
A = list(map(int,sys.stdin.readline().split()))
x,y = map(int,sys.stdin.readline().split())
cnt = 0
for num in A:
    if num >= y:
        cnt+=1
print(round(N*(x/100)),cnt)