import sys

maps = [[0 for x in range(100)]for s in range(100)]
for _ in range(4):
    x1,y1,x2,y2 = map(int, sys.stdin.readline().rstrip().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            if maps[i][j] !=1:
                maps[i][j] = 1
cnt=0
for i in range(100):
    cnt+=maps[i].count(1)
print(cnt)