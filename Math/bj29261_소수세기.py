# 1. n보다 작은 소수를 모두 구한다.
def prime(p):
    n = p - 1
    arr = [True for i in range(n+1)]
    primes = []
    for i in range(2,int(n**0.5)+1):
        if arr[i] != False:
            for j in range(2*i,n+1,i):
                arr[j] = False
    for k in range(2,n):
        if arr[k] == True:
            primes.append(k)
    return primes

# 2. Array에서 더해서 K가 되는 두 수의 집합을 모두 구한다.
def setOfTwoFactor(arr, k):
    result = []
    for i in range(len(arr)):
        for j in range(i,len(arr)):
            if arr[i] + arr[j] == k-1:
                result.append([arr[i], arr[j]])
    return result

# 3. 현재 상태를 계속해서 갱신해 나가면서 지울수 있는 만큼 모두 지운다.
def divideNum(n):
    tmp = prime(n)
    return setOfTwoFactor(tmp, n)

def DP(n):
    print(n)
    s = divideNum(n)
    print(s)
    for (x,y) in s:
        m, n = divideNum(x), divideNum(y)
        print(m,n)



# def DP(n, memo):
#     if n in memo:
#         return memo[str(n)]

#     s = divideNum(n)
#     print(s)
#     max_count = 0

#     for (x, y) in s:
#         m, n = divideNum(x), divideNum(y)
#         key = tuple(sorted([x, y]))  # 두 소수의 조합을 정렬된 튜플로 표현
#         max_count = max(max_count, DP(x, memo) + DP(y, memo) + 1)
#         print(m,n)
#     print(memo)
#     memo[str(n)] = max_count
#     return max_count

# def solve(n):
#     memo = {}
#     return DP(n, memo)


# print(solve(17))