import sys
# 자연수 N보다 작은 소수들을 구함
def prime_list(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정(소수로 간주)
    sieve = [True] * n
    
    k=n
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if k==1: break
        if sieve[i] == True:           # i가 소수인 경우 
            while k%i==0: k/=i; print(i)
            for j in range(i+i, n, i): # i이후 i의 배수들을 False 판정
                sieve[j] = False
    if k!=1: print(int(k))
    return 1
N = int(sys.stdin.readline().rstrip())
prime_list(N)