# 5*x + 3*y = N 이되는 가능한 L = (x,y) 중에서 최소값을 찾는 문제.
import sys
N = int(sys.stdin.readline().rstrip())
row,col,possible = int(N/5), int(N/3), []
for i in range(0,row+1):
    for j in range(0,col+1):
        if N == 5*i+3*j: possible.append(i+j)
if possible : print(min(possible))
else: print(-1)

# 숏코딩
# n=int(input())
# print(-(n in[4,7])or n-2*n//5*2)