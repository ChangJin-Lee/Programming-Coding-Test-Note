import sys
# 자연수 N보다 작은 소수들을 구함
def eratos(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    sieve = [True] * n
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:           # i가 소수인 경우
            for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False
    return [i for i in range(2,n) if sieve[i]==True]
def goldbach(primes,n):
    min, p, q = primes[-1] - primes[0], 0, 0
    for i in range(len(primes)):
        for j in range(len(primes)):
            if primes[i] + primes[j] == n and  min > abs(primes[i] - primes[j]): min = abs(primes[i] - primes[j]); p=i; q=j
    print(primes[p],primes[q],sep=" ")
    return 1
N = int(sys.stdin.readline().rstrip())
for _ in range(N):
    n = int(sys.stdin.readline().rstrip())
    goldbach(eratos(n),n)
