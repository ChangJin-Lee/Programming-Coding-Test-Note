import sys
n = int(sys.stdin.readline().rstrip())
m = list(map(int, sys.stdin.readline().rstrip().split()))
m = sorted(m)
print(m[0] * m[-1])