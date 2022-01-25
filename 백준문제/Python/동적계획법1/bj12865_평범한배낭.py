import sys

n,k = map(int,sys.stdin.readline().rstrip().split())
bag = [(0,0)]
dp = [[0 for _ in range(100001)] for _ in range(101)]

for i in range(n):
    bag.append(list(map(int,sys.stdin.readline().rstrip().split())))

for i in range(1, n+1):
    for j in range(1, k+1):
        w = bag[i][0]
        v = bag[i][1]
        if j < w:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(v + dp[i-1][j-w], dp[i-1][j])


print(dp[n][k])

