# 행렬로 나타낸 map에서 0은 빈공간 1은 벽 2는 바이러스를 나타낸다.
# 바이러스는 벽이 아닌 빈 공간에 확산이 된다.
# 아직 다행히 확신되기 전이다. 벽을 3개 무조건 세워야 한다.
# 벽을 세운 후 바이러스가 빈칸으로 모두 퍼져 나갔을때 바이러스가 없는 공간은
# 안전 영역이라고 부른다.
# 안정 영역의 크기의 최댓값을 출력하자.

# -> 일단 기본 구조는 bfs다. 여기서 조금씩 변형하면서 생각해보자.
# 일단 바이러스가 퍼져 나가는 것은 bfs로 돌면서 0을 2로 바꾼다고 생각하면 될것같다.
# 벽을 세우는 것은 어떻게 할까? 음... 행렬의 중복되지않은 빈 공간인 세 지점에 1을 넣는다고 해보자.
# 그 다음 경우마다 bfs를 돌려본 다음 안전 영역의 크기를 계산하자.

import sys
from collections import deque
import copy

def findvirus(maps,n,m,visit):
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 2 and visit[i][j] == 0:
                #print(i,j)
                return i,j
    # 여기 리턴값을 -1,-1로 처음에 설정했다가 매우 긴 시간을 방황했는데,
    # 파이썬에서는 인덱스 값으로 -1이 들어갈 경우 맨 마지막 인덱스가 되기 때문에
    # 3<n,m<8 이므로 인덱스 10을 더이상 바이러스 발원지가 없다는 표식으로 사용하자.
    return 10,10

# bfs는 바이러스가 퍼져나가는 것을 실행하는 함수임.
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
# 3개의 벽을 치는 모든 경우의 수에 대해 바이러스가 퍼지는 상황을 대입해보자.
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