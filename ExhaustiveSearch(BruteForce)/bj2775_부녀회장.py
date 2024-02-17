import sys
T = int(sys.stdin.readline().rstrip())
for i in range(T):
    row, col = int(sys.stdin.readline().rstrip()),int(sys.stdin.readline().rstrip())
    rooms = [[0 for _ in range(col)] for _ in range(row+1)]
    for k in range(col): rooms[0][k] = k+1
    # print(rooms)
    for j in range(1,row+1): 
        for m in range(0,col):
            rooms[j][m] = sum(rooms[j-1][:m+1])
    print(rooms[row][col-1])

# 숏코딩
# import math
# exec('k=int(input());n=int(input());print(math.comb(n+k,n-1));' * int(input()))