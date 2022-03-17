import sys
import copy
n = int(sys.stdin.readline().rstrip())
stack = [] ## 쿼리를 쌓을 스택
list = [] ## 문제목록을 나타낼 리스트
for _ in range(n):
    command = str(sys.stdin.readline().rstrip())
    if command[0] == 'a':
        print(command[-1])
        list.append(int(command[-1]))
    elif command[0] == 's':
        if list != []:
            list.pop(-1)
            if list == []:
                print(-1)
            else:
                print(list[-1])
        else:
            print(-1)
    elif command[0] == 't':
        if int(command[-1]) == 1:
            list = []
            print(-1)
        elif int(command[-1]) > 1:
            list = stack[int(command[-1]) - 2]
            if list == []:
                print(-1)
            else:
                print(list[-1])
    stack.append(copy.deepcopy(list))
    #print(stack, list)

#
# import sys
#
# input = sys.stdin.readline
#
# n = int(input())
#
# q_list = [[]]
# def print_num(q_list) :
#     if q_list :
#         print(q_list[-1])
#     else :
#         print(-1)
#
# for _ in range(n) :
#     query = input().split()
#     if query[0] == 'a' :
#         q_list.append(q_list[-1] + [int(query[1])])
#
#     elif query[0] == 's' :
#         q_list.append(q_list[-1][:-1])
#
#     else :
#         q_list.append(q_list[int(query[1]) - 1])
#
#     print_num(q_list[-1])