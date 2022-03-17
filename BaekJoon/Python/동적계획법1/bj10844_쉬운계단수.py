# 이 문제의 핵심은 각 자릿수를 배열에 담아서 계산한다는 것임
# 계속해서 현재 i번째의 상태를 갱신해 간다고 생각하셈 꼭!

import sys

n = int(sys.stdin.readline().rstrip())

dp = [[0 for i in range(10)] for j in range(n)]

for i in range(1,10):
    dp[0][i] = 1

for i in range(1,n):
    for j in range(10):
        if j == 9:
            dp[i][j] = dp[i-1][1]
        elif j == 0:
            dp[i][j] = dp[i-1][8]
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

print(sum(dp[-1])%1000000000)