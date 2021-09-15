import sys
n = int(sys.stdin.readline().rstrip())
xs = list(map(int,sys.stdin.readline().rstrip().split()))
sortedxs = []
for x in xs:
    if x not in sortedxs: sortedxs.append(x)
sortedxs = sorted(sortedxs)
for i in range(n):
    print(sortedxs.index(xs[i]),end=" ")