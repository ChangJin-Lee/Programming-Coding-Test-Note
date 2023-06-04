import sys
n = list(map(int,sys.stdin.readline().rstrip()))
n = sorted(n)
n = list(reversed(n))
print("".join(map(str,n)))
