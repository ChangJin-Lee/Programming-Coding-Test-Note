import sys

n = int(sys.stdin.readline().rstrip())

arr = []
for _ in range(n):
    point = int(sys.stdin.readline().rstrip())
    arr.append(point)


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

print(arr)




