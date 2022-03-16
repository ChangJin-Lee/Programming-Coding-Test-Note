# https://www.acmicpc.net/problem/24510
import sys

c = int(sys.stdin.readline().rstrip())
result = 0
for _ in range(c):
    strings = str(sys.stdin.readline().rstrip())
    cnt = strings.count("for") + strings.count("while")
    if result < cnt:
        result = cnt
print(result)


# 왜 이렇게 생각했지? count를 쓰면 훨씬 편한거였는데...
# import sys
#
# for_, while_ = "for", "while"
# c = int(sys.stdin.readline().rstrip())
# result = 0
# for _ in range(c):
#     strings = list(sys.stdin.readline().rstrip())
#     cnt=0
#     while True:
#         if strings == []:
#             break
#         t = strings.pop(0)
#         pops = []
#         if t == 'f' and len(strings) >=2:
#             for i in range(2):
#                 pops.append(strings.pop(0))
#             if pops == ['o','r']:
#                 cnt+=1
#         pops.clear()
#         if t == 'w' and len(strings) >=4:
#             for i in range(4):
#                 pops.append(strings.pop(0))
#             if pops == ['h','i','l','e']:
#                 cnt+=1
#         pops.clear()
#     if result <= cnt:
#         result = cnt
# print(result)