import sys
def fibonacci(n):
    if n==1: return 1
    elif n==0: return 0
    else: return fibonacci(n-1) + fibonacci(n-2)

n = int(sys.stdin.readline().rstrip())
print(fibonacci(n))