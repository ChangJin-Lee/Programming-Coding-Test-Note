import sys
N, M = map(int,sys.stdin.readline().rstrip().split())
cards = list(map(int,sys.stdin.readline().rstrip().split()))
sums = 0
for i in range(N):
    for j in range(i+1,N):
        for k in range(j+1,N):
            compare = cards[i]+cards[j]+cards[k]
            if compare > sums and compare <= M: sums = compare
print(sums)
