# 조합 구현.
# 재귀를 이용한 구현
# itertools를 쓸 수도 있으나 직접 구현하는 방법으로 알고 있길 바람.
import sys
import itertools

def sums(a,b):
    sum=0
    for i in range(a,b+1):
        sum+=i
    return sum

# import copy
#
# 얘는 배열의 값이 모두 달라야지만 정상적으로 동작함.
# def combination(arr, r):
#     result = []
#     # 1.
#     arr = sorted(arr)
#     used = [0 for _ in range(len(arr))] # 0이면 사용안됨. 1이면 사용됨
#
#     # 2.
#     def generate(chosen):
#         if len(chosen) == r:
#             result.append(copy.deepcopy(chosen))
#             print(chosen)
#             return
#
#         # 3.
#         start = arr.index(chosen[-1]) + 1 if chosen else 0
#         for nxt in range(start,len(arr)):
#             if used[nxt] == 0 and (nxt == 0 or arr[nxt-1] != arr[nxt] or used[nxt-1]):
#                 chosen.append(arr[nxt])
#                 used[nxt] = 1
#                 generate(chosen)
#                 chosen.pop()
#                 used[nxt] = 0
#     generate([])
#     return result

n, q = map(int, sys.stdin.readline().rstrip().split())
a = list(map(int,sys.stdin.readline().rstrip().split()))

league = list(itertools.combinations(a,2))


for i in range(q):
    x,y = map(int, sys.stdin.readline().rstrip().split())
    result = 0
    add = sums(n-x+1,n-1)
    sub = y-x
    for j in range(x-1,y):
        t = league[add:add+sub]
        sub-=1
        add+=n-j-1
        if t!=[]:
            for k in t:
                result += k[0]*k[1]
    print(result)