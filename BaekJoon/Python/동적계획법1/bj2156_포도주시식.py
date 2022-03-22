import sys

n = int(sys.stdin.readline().rstrip())

wine = [0 for _ in range(n)]
dp = [0 for _ in range(n)]

for i in range(n):
    input = int(sys.stdin.readline().rstrip())
    wine[i] = input

dp[0] = wine[0]

if n > 1:
    dp[1] = wine[0] + wine[1]
if n > 2:
    dp[2] = wine[2] + max(wine[0], wine[1])

for i in range(3,n):
    dp[i] = wine[i] + max(dp[i-2], wine[i-1] + dp[i-3], wine[i-1] + dp[i-4])

print(max(dp))