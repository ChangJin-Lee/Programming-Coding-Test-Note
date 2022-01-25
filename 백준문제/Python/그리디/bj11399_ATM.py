import sys

n = int(sys.stdin.readline())
p = list(map(int, sys.stdin.readline().rstrip().split()))
q = [_ for _ in p]

p = sorted(p)
for i in range(n):
    for j in range(i):
        q[i]+=p[j]

print(sum(q))