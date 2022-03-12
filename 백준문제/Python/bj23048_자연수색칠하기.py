import sys
def eratos(n):
    primes = []
    checks = [0 for x in range(n+1)]
    checks[1] = 1
    cnt = 1
    for i in range(2,n+1):
        if checks[i] == 0:
            for j in range(i,n+1,i):
                checks[j] = cnt+1
            primes.append(i)
            cnt+=1
    return checks

n = int(sys.stdin.readline().rstrip())
colors = [x for x in range(n+1)]
primes = eratos(n)
# print(colors)
# print(primes)
print(max(primes))
for i in range(1,n+1):
    print(primes[i], end=" ")