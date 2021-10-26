# 2중문으로 짜는 dp
import sys

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
dp = [1 for i in range(1001)]
result = 0


for i in range(1,n):
    max = 0
    for j in range(i):
        if a[i] > a[j] and dp[j] >= max:
            max = dp[j]
            dp[i] = max+1

for i in range(n):
    if result < dp[i]:
        result = dp[i]

# print(dp)
print(result)
