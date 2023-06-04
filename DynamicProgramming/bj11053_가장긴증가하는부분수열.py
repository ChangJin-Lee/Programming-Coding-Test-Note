# 2중문으로 짜는 dp
import sys

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
a2 = list(reversed(a))
dp = [1 for i in range(1001)]
dp2 = [1 for i in range(1001)]
result = 0


for i in range(1,n):
    max = 0
    for j in range(i):
        if a[i] > a[j] and dp[j] >= max:
            max = dp[j]
            dp[i] = max+1
    max = 0
    for j in range(i):
        if a2[i] > a2[j] and dp2[j] >= max:
            max = dp2[j]
            dp2[i] = max + 1


for i in range(n):
    dp[i] = dp[i] + dp2[n-1-i]
    if result < dp[i]:
        result = dp[i]
#
# print(dp)
# print(dp2)
print(result-1)
