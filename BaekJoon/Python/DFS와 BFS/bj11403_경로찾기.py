# 가중치가 없는 방향 그래프 G가 주어짐. 모든 정점 (i,j)에 대해
# i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하자.
import sys
from collections import deque

def bfs(adjlist,graph,start):
    n = len(graph)
    visit = [0 for _ in range(n)]
    q = deque()
    q.append(start)

    while q:
        cur = q.popleft()
        graph[start][cur] = 1
        for i in range(n):
            # 여기에 cur가 아니라 start라고 생각했음. 왜?
            if adjlist[cur][i] == 1 and visit[i] == 0:
                #print("({}-{})".format(cur,i))
                q.append(i)
                visit[i] = 1
    # 자신에게 돌아오는 경우가 없을 때
    if visit[start] == 0:
        graph[start][start] = 0
    return graph

n = int(sys.stdin.readline().rstrip())
adjlist = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
paths = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    paths = bfs(adjlist,paths,i)
for path in paths:
    print(" ".join(str(x) for x in path))