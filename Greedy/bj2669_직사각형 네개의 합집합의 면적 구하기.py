# 그리디로 푸는 대표적인 문제였다.
# 코드를 자세히 보니까 파이썬 배열의 count()함수는 안쓰는게 좋을거 같다.
# 시간 복잡도가 너무 크다.

import sys

maps = [[0 for x in range(100)]for s in range(100)]
for _ in range(4):
    x1,y1,x2,y2 = map(int, sys.stdin.readline().rstrip().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
                maps[i][j] = 1
cnt=0
for i in range(100):
    for j in range(100):
        if maps[i][j] == 1:
            cnt+=1
print(cnt)