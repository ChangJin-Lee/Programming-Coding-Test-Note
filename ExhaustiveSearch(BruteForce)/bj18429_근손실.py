import sys

# linear 하게 짜는법. 속도 빠름. 배열을 return 할 수 있음.
def permute(arr):
    result = [arr[:]]
    c = [0] * len(arr)
    i = 0
    while i < len(arr):
        if c[i] < i:
            if i % 2 == 0:
                arr[0], arr[i] = arr[i], arr[0]
            else:
                arr[c[i]], arr[i] = arr[i], arr[c[i]]
            result.append(arr[:])
            c[i] += 1
            i = 0
        else:
            c[i] = 0
            i += 1
    return result


# 방법2. 재귀적으로 만들기. print하는데 특화됨. 속도 느림
# def solution(arr,k):
#     n = len(arr)
#     picked = []
#
#     def recur():
#         if len(picked) == k:
#             print(picked)
#             return picked
#         for i in range(n):
#             if arr[i] not in picked:
#                 picked.append(arr[i])
#                 recur()
#                 picked.pop()
#
#     recur()

n, k = map(int, sys.stdin.readline().rstrip().split())
A = list(map(int, sys.stdin.readline().rstrip().split()))
PA = permute(A)
# PA = solution(A,n)
result = 0
for i in range(len(PA)):
    check = False
    start = 500
    for j in range(n):
        start += PA[i][j] - k
        if start < 500:
            check = True
            break
    if check == False:
        result += 1
print(result)


# def dfs(depth, t):
#     global cnt
#     if depth == N:
#         cnt += 1
#         return;
#     for i in range(N):
#         if check[i] or t + nums[i] - K < 0:
#             continue
#         check[i] = 1
#         dfs(depth + 1, t + nums[i] - K)
#         check[i] = 0
#
#
# N, K = map(int, input().split())
# nums = list(map(int, input().split()))
# check, cnt = [0] * N, 0
# dfs(0, 0)
# print(cnt)