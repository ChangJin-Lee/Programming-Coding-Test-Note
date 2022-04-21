# 그림을 자세히 보면 직선이 1*1 사각형의 교점을 지날때를 자세히 보면
# 그 작은 사각형이 큰 사각형과 닮음일 때임.
# 그 작은 사각형이 만들어 지는 주기는 두 수의 최대공약수일때인 걸 알 수 있음.
# 즉 answer = w * h - ( w + h - gcd)이고 이때 gcd는 w,h의 최대공약수임.
def axiswh(w,h):
    n = min(w,h)+1
    chk = [False for x in range(n)]
    primes = []
    gcd = 1
    for i in range(2,n):
        if chk[i] == False:
            primes.append(i)
            for j in range(i,n,i):
                chk[j] = True
    for prime in primes:
        while w%prime == 0 and h%prime ==0:
            gcd *= prime
            w = w//prime
            h = h//prime
    return gcd

def solution(w,h):
    answer = w*h
    #w * h - (w+h-최대공약수)
    # 직선 y = a*x 를 생각하자.
    # 우선 기울기 a = w/h 를 기약분수의 형태로 만들자.
    if w == h:
        answer -= w
    else:
        gcd= axiswh(w,h)
        answer -= w + h - gcd
    return answer


print(solution(8,12)) # 80