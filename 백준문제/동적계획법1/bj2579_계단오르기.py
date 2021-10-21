import sys

n = int(sys.stdin.readline().rstrip())

stair = []
dp = [[0 for i in range(n)] for j in range(3)]
for i in range(n):
    point = int(sys.stdin.readline().rstrip())
    for j in range(3):
        dp[j][i] = point

# ## dp를 -1로 갱신하면 해당하는 층을 밟았다
# ## dp를 0으로 갱신하면 해당하는 층은 밟지않았다

# 10으로 시작
stair.append(dp[0][0])
dp[0][0] = -1
dp[0][1] = 0

# 01로 시작
stair.append(dp[1][1])
dp[1][0] = 0
dp[1][1] = -1

# 11로 시작
stair.append(dp[2][0] + dp[2][1])
dp[2][0] = -1
dp[2][1] = -1

# stair 는 현재까지 올라온 계단의 최댓값

for i in range(3):
    for j in range(2,n-1):
        print(i,j)
        print(stair)
        print(dp)
        if dp[i][j] != -1:
            if dp[i][j-2] == -1 and dp[i][j-1] != -1:
                stair[i] += dp[i][j]
                dp[i][j] = -1
                dp[i][j-1] = 0
            elif dp[i][j-2] != -1 and dp[i][j-1] == -1:
                if dp[i][j] > dp[i][j+1]:
                    stair[i] += dp[i][j]
                    dp[i][j] = -1
                else:
                    stair[i] += dp[i][j+1]
                    dp[i][j] = 0
                    dp[i][j+1] = -1
            elif dp[i][j-2] == -1 and dp[i][j-1] == -1:
                dp[i][j] = 0

for i in range(3):
    if dp[i][-1] != -1:
    # 두번 건너서 마지막으로 가는 경우
        if dp[i][-4] != -1 and dp[i][-3] == -1 and dp[i][-2]!=-1:
            stair[i] += dp[i][-1]
            dp[i][-1] = -1
    # 한번 건너서 마지막으로 가는 경우
        elif dp[i][-3] != -1:
            stair[i] += dp[i][-1]
            dp[i][-1] = -1


print(max(stair))
print(stair)
print(dp)


################## 최댓값만을 찾아가는 해결법 해결X
#
# result += dp[-1]
# dp[-1]=-1
#
# ## dp를 -1로 갱신하면 해당하는 층을 밟았다
# ## dp를 0으로 갱신하면 해당하는 층은 밟지않았다
#
# for i in range(n):
#     dpindex = dp.index(max(dp))
#     print(dp, result)
#     if dpindex == 0:
#         if dp[1] == -1 and dp[2] == -1:
#             dp[0]=0
#         else:
#             result += dp[0]
#             dp[0]=-1
#     else:
#         if dp[dpindex-1] == -1 and dp[dpindex+1] == -1:
#             dp[dpindex] = 0
#         else:
#             result += dp[dpindex]
#             dp[dpindex] = -1
#
# print(result)




################## 인덱스 0부터 for문을 돌면서 계속해서 선택하는 방법 해결X

# if n<3: arr[-1] = sum(arr)
# elif n == 3:
#     if arr[2] > arr[1]: arr[2]+=arr[0]
#     else: arr[1]+=arr[0]; arr[2] = arr[1]
# else:
#     step = 1
#     i = 0
#     while i < n-2:
#         # if i == n-3:
#         #     if step == 0:
#         #         arr[-2]+=arr[-3]
#         #         arr[-1]+=arr[-2]
#         #         break
#         if arr[i+1] > arr[i+2]:
#             if step<2:
#                 arr[i+1]+=arr[i]
#                 i+=1
#                 step+=1
#             else:
#                 arr[i+2]+=arr[i]
#                 i+=2
#                 step=0
#         elif arr[i+1] < arr[i+2]:
#             arr[i+2] += arr[i]
#             i+=2
#             step=0
#     if i < n-1 : arr[-1] += arr[-2]

# print(arr)




