# https://www.acmicpc.net/problem/24509
# 국어, 영어, 수학, 과학 순서대로 상품을 받는 학생의 번호를 공백으로 구분하여 출력한다.
import sys
n = int(sys.stdin.readline().rstrip())
students = [list(map(int,sys.stdin.readline().rstrip().split())) for x in range(n)]
result = []
for i in range(1,5):
    tmax,k = 0,0
    for j in range(n):
        if students[j][0] != 101:
            if tmax < students[j][i]:
                tmax = students[j][i]
                k = j
            elif tmax == students[j][i]:
                if students[k][0] > students[j][0]:
                    k = j
    result.append(students[k][0])
    students[k][0] = 101
print(" ".join(str(x) for x in result))