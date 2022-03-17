import sys
# 취준할때 한 코딩
condition = 1000000
checks = [0 for x in range(condition+1)]
oddprimes = []
for i in range(2,condition+1):
    if checks[i] == 0:
        for j in range(i,condition+1,i):
            checks[j] = 1
        if i%2 == 1:
            oddprimes.append(i)
print(oddprimes)

while True:
    n = int(sys.stdin.readline().rstrip())
    t = False
    if n == 0 or n<6 or n>condition: break
    if n<999983:
        for i in range(len(oddprimes)):
            if oddprimes[i] > n:
                targetprimes = oddprimes[0:i]
                break
    else:
        targetprimes = oddprimes
    for i in range(len(targetprimes)):
        for j in range(len(targetprimes)-1,i,-1):
            if oddprimes[i] + oddprimes[j] == n:
                b,a = oddprimes[j],oddprimes[i]
                t = True
                break
            elif oddprimes[i] + oddprimes[j] < n:
                break
        if t == True:
            break
    if t==False:
        print("Goldbach's conjecture is wrong.")
    else:
        print(n,"=",a,"+",b)






# 학부때 하던 코딩
# # 자연수 N보다 작은 소수들을 구함
# def eratos(n):
#     # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
#     sieve = [True] * n
#     m = int(n ** 0.5)
#     for i in range(2, m + 1):
#         if sieve[i] == True:           # i가 소수인 경우
#             for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
#                 sieve[j] = False
#     return [i for i in range(2,n) if sieve[i]==True]
# def goldbach(primes,n):
#     min, p, q = primes[-1] - primes[0], 0, 0
#     for i in range(len(primes)):
#         for j in range(len(primes)):
#             if primes[i] + primes[j] == n and  min > abs(primes[i] - primes[j]): min = abs(primes[i] - primes[j]); p=i; q=j
#     print(primes[p],primes[q],sep=" ")
#     return 1
# N = int(sys.stdin.readline().rstrip())
# for _ in range(N):
#     n = int(sys.stdin.readline().rstrip())
#     goldbach(eratos(n),n)
