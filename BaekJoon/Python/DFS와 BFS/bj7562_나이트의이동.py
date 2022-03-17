# https://www.acmicpc.net/problem/7562
# we need to calculate night position
# input values
# 3
# 8
# 0 0
# 7 0
# 100
# 0 0
# 30 50
# 10
# 1 1
# 1 1

import sys
from collections import deque

def bfs(maps,fx,fy,lx,ly): # 체스판 배열 maps, 초기위치 fx,fy, 목적지위치 lx,ly
    l = len(maps)
    visit = [[0 for _ in range(l)] for _ in range(l)]
    q = deque()
    q.append((fx,fy))

    while q:
        (x,y) = q.popleft()
        for (dx,dy) in [(1,2),(2,1),(2,-1),(1,-2),(-1,-2),(-2,-1),(-2,1),(-1,2)]:
            nx,ny = x+dx, y+dy

            if 0 <= nx < l and 0<= ny < l:
                if visit[nx][ny] == 0:
                    visit[nx][ny] = 1
                    q.append((nx, ny))
                    maps[nx][ny]=maps[x][y]+1
                    if (nx,ny) == (lx,ly):
                        return maps[nx][ny]



t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    l = int(sys.stdin.readline().rstrip())
    maps = [[0 for _ in range(l)] for _ in range(l)]
    x, y = map(int, sys.stdin.readline().rstrip().split())
    tx, ty = map(int, sys.stdin.readline().rstrip().split())
    if (x,y) == (tx,ty):
        print(0)
    else:
        result = bfs(maps,x,y,tx,ty)
        print(result)
