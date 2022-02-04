import sys

def result(n):
    degreesum = 0
    # a0가 현재 노브의 각도.
    # a1은 돌려야 하는 노브의 각도.
    a0 = int(sys.stdin.readline().rstrip())
    for _ in range(n):
        a1 = int(sys.stdin.readline().rstrip())
        # 1. 왼쪽으로 돌리는 경우
        if a1 > a0:
            leftdegree = 360 -a1 + a0
        elif a1 == a0:
            leftdegree = 0
        elif a1 < a0:
            leftdegree = a0 - a1
        # 2. 오른쪽으로 돌리는 경우
        if a1 > a0:
            rightdegree = a1 - a0
        elif a1 == a0:
            rightdegree = 0
        elif a1 < a0:
            rightdegree = 360 -a0 + a1

        if leftdegree < rightdegree:
            degreesum += leftdegree
        else:
            degreesum += rightdegree
        #print(a0, a1, leftdegree, rightdegree, degreesum)
        a0 = a1
    print(degreesum)
n = int(sys.stdin.readline().rstrip())

result(n)