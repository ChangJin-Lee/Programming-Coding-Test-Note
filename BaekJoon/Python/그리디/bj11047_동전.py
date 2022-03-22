# test input values
# 10 4200
# 1
# 5
# 10
# 50
# 100
# 500
# 1000
# 5000
# 10000
# 50000

import sys

n,k = map(int, sys.stdin.readline().rstrip().split())
coins = []
for _ in range(n):
    t = int(sys.stdin.readline().rstrip())
    coins.append(t)

coins = list(reversed(coins))

cnt = 0
for i in range(n):
    coin = coins.pop(0)
    if coin <= k:
        t = k // coin
        cnt += t
        k -= coin*t
print(cnt)

# 옛날에 내가 했던 코딩. 학부 2학년
# cnt = 0
# tcoin = 1
# while True:
#     for i in range(n):
#         if coins[i] < k:
#             temp = coins[i]
#             break
#     print(k, tcoin,cnt,coins)
#     temp = k//tcoin
#     cnt +=temp
#     k = k%(tcoin*temp)
#     if k == 0 : break
# print(cnt)
