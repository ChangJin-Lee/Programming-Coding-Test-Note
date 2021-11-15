import sys
n = int(sys.stdin.readline().rstrip())
d = list(map(int, sys.stdin.readline().rstrip().split()))
s = list(map(int, sys.stdin.readline().rstrip().split()))

smin = s[0]
s[-1] = 10001

answer = 0
for i in range(n-1):
    if s[i] <= smin:
        smin = s[i]
    answer += smin * d[i]

print(answer)
