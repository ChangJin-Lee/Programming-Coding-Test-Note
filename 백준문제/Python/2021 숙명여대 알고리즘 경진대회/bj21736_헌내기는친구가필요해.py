import sys
from collections import deque
# def dfs(graph, start_node):
#     visit = list()
#     stack = list()
#
#     stack.append(start_node)
#
#     while stack:
#         node = stack.pop()
#         if node not in visit:
#             visit.append(node)
#             stack.extend(graph[node])
#     return visit

n,m = map(int,sys.stdin.readline().rstrip().split())
maps = [list(sys.stdin.readline()) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

def bfs(x,y):
    cnt = 0 # 방문 횟수
    q = deque() # 큐 선언
    visited[x][y] = 1 # 도연이가 있는 위치를 방문 처리
    q.append((x,y)) # 큐에 추가

    while q:
        x,y = q.popleft()
        for dx,dy in [(1,0),(0,1),(-1,0),(0,-1)]:
            #도연이의 이동 좌표
            nx, ny = x+dx, y+dy

            # 도연이 이동 좌표가 맵안에서 처음 방문한곳을 체크
            if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0:
                if maps[nx][ny] != 'X':
                    q.append((nx,ny))
                    visited[nx][ny] = 1
                    if maps[nx][ny] == 'P':
                        cnt+=1
    return cnt
for i in range(n):
    for j in range(m):
        if maps[i][j] == "I":
            cnt = bfs(i,j)
if cnt!=0:
    print(cnt)
else:
    print('TT')