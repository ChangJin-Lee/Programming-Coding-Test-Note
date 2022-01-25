import sys

n,k = map(int, sys.stdin.readline().rstrip().split())
coins = []

for _ in range(n):
    input = int(sys.stdin.readline().rstrip())
    coins.append(input)

coins = reversed(coins)

cnt = 0
tcoin = 1
while True:
    for i in range(n):
        if coins[i] < k:
            temp = coins[i]
            break
    print(k, tcoin,cnt,coins)
    temp = k//tcoin
    cnt +=temp
    k = k%(tcoin*temp)
    if k == 0 : break
print(cnt)
