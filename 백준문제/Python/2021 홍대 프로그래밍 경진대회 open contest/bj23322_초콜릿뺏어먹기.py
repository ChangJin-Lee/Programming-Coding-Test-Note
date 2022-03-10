import sys
n,k = map(int,sys.stdin.readline().rstrip().split())
a = list(map(int,sys.stdin.readline().rstrip().split()))

days,cnt = 0,0
for i in range(k,n):
    if a[i-k] < a[i]:
        cnt += a[i] - a[i-k]
        a[i] = a[i] - a[i-k]

print(a,cnt)