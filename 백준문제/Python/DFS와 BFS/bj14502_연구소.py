import sys
from collections import deque
import copy

def findvirus(maps,n,m,visit):
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 2 and visit[i][j] == 0:
                #print(i,j)
                return i,j
    return 10,10

def bfs(maps,n,m):
    q = deque()
    visit = [[0 for _ in range(m)] for _ in range(n)]
    vx,vy = findvirus(maps,n,m,visit) # vx, vy는 바이러스의 첫 위치
    q.append((vx,vy))
    #print("vx,vy",vx,vy)
    visit[vx][vy] = 1

    while q:
        (x,y) = q.popleft()
        for (dx,dy) in [(1,0),(0,1),(-1,0),(0,-1)]:
            (nx,ny) = (x+dx, y+dy)
            if 0<= nx < n and 0<= ny < m and visit[nx][ny] == 0:
                visit[nx][ny] = 1
                #print("nx,ny",nx,ny)
                #print("visit", visit[-1][-1])
                if maps[nx][ny] == 0:
                    maps[nx][ny] = 2
                    q.append((nx,ny))
                elif maps[nx][ny] == 1:
                    tx,ty = findvirus(maps,n,m,visit)
                    #print("tx,ty",tx,ty)
                    if (tx,ty) != (10,10):
                        visit[tx][ty] = 1
                        q.append((tx,ty))
                else:
                    q.append((nx,ny))
    cnt = 0
    for map in maps:
        #print(map)
        cnt += map.count(0)
    #print("cnt", cnt)
    #for v in visit:
        #print(v)
    return cnt


n,m = map(int,sys.stdin.readline().rstrip().split())
maps = [list(map(int,sys.stdin.readline().rstrip().split())) for _ in range(n)]
coordinate = []
for i in range(n):
    for j in range(m):
        coordinate.append((i,j))
#print(maps)
safezones = 0
cnt = 0
for (a1,a2) in coordinate:
    if maps[a1][a2] == 0:
        for (b1,b2) in coordinate[a1*m+a2+1:]:
            if maps[b1][b2] == 0:
                for (c1,c2) in coordinate[b1*m+b2+1:]:
                    #print((a1,a2),(b1,b2),(c1,c2))
                    if maps[c1][c2] == 0:
                        cnt+=1
                        case = copy.deepcopy(maps)
                        case[a1][a2], case[b1][b2], case[c1][c2] = 1,1,1
                        t = bfs(case,n,m)
                        if t > safezones:
                            safezones = t
print(safezones)
#print(cnt)