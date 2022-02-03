import sys

N = int(sys.stdin.readline().rstrip())
print(bin(~N + 1))