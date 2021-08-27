import sys
N = int(sys.stdin.readline().rstrip())
row,col,possible = int(N/5), int(N/3), []
# print(row,col)
for i in range(0,row+1):
    for j in range(0,col+1):
        if N == 5*i+3*j: possible.append(i+j)
# print(possible)
if possible : print(min(possible))
else: print(-1)

# 숏코딩
# n=int(input())
# print(-(n in[4,7])or n-2*n//5*2)