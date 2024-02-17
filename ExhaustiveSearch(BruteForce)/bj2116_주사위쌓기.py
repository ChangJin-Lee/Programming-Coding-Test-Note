# 스스로 풀었고 다른 사람의 풀이도 봤다.
# 다들 나랑 비슷한 브루트 포스로 풀었다. 1번 주사위의 1~6이 윗면이 오는 6가지 경우를
# 각각 생각하면 되는 문제였다.
import sys
import copy

# a-f, b-d, c-e ||| 0-5, 1-3, 2-4
n = int(sys.stdin.readline().rstrip())
dises = []
for i in range(n):
    dises.append(list(map(int, sys.stdin.readline().rstrip().split())))
result = 0
for i in range(1,7):
    testcase = copy.deepcopy(dises)
    temp = 0
    top = i
    for j in range(n):
        p = testcase[j].index(top)
        if p == 0:
            testcase[j][0] = 0
            top = testcase[j][5]
            testcase[j][5] = 0
        elif p == 1:
            testcase[j][1] = 0
            top = testcase[j][3]
            testcase[j][3] = 0
        elif p == 2:
            testcase[j][2] = 0
            top = testcase[j][4]
            testcase[j][4] = 0
        elif p == 3:
            testcase[j][3] = 0
            top = testcase[j][1]
            testcase[j][1] = 0
        elif p == 4:
            testcase[j][4] = 0
            top = testcase[j][2]
            testcase[j][2] = 0
        elif p == 5:
            testcase[j][5] = 0
            top = testcase[j][0]
            testcase[j][0] = 0
        temp += max(testcase[j])
    if result < temp:
        result = temp
print(result)