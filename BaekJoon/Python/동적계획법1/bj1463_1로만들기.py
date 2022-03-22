# 이 문제의 핵심은 if - else문이 아니라 각각의 경우가 if문으로 되어 있다는 거임
# n번째를 구할때 n-1까지 배열을 보고 n번째를 구해야함

import sys

n = int(sys.stdin.readline().rstrip())

if n == 1: print(0)
elif n == 2: print(1)
elif n == 3: print(1)
elif n == 4: print(2)
else:
    dp = [0 for i in range(n+1)]

    dp[1] = 0
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2
    cnt = [0 for i in range(3)]

    for i in range(5,n+1):
        x1,x2,x3 = i,i,i
        for j in range(3): cnt[j] = 1000000
        if x3%3 == 0:
            x3 = x3//3
            cnt[2] = 1 + dp[x3]
        if x2%2 == 0:
            x2 = x2//2
            cnt[1] = 1 + dp[x2]
        x1-=1
        cnt[0] = 1 + dp[x1]
        dp[i] = min(cnt)
    print(dp[n])