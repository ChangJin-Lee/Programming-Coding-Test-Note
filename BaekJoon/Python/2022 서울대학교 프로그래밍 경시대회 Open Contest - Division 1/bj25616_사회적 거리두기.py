import sys
from collections import deque


def bfs(axis, n, k):
    q = deque()
    q.append(axis)

    while q:
        aaxis = q.popleft()
        l = []
        for [nx, ny] in ([1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]):
            chk = False
            for t in aaxis:
                if abs(t[0]+nx)+abs(t[1]+ny) > k:
                    chk = True
                    break
                else:
                    l.append(t[0]+nx, t[1]+ny, abs(t[0]+nx)+abs(t[1]+ny))
            if chk == True:
                break
        q.append(l)


n, k = map(int, sys.stdin.readline().split())
axis = []
for i in range(n):
    dx, dy = map(int, sys.stdin.readline().split())
    axis.append([dx, dy, abs(dx)+abs(dy)])

bfs(axis, n, k)
