# 처음 접근은 옳았으나 디테일이 부족했음. 단순히 bfs, dfs만을 사용해서는 풀기 어려움.
# 모든 간선에서 모든 간선으로 가는 경우의 수를 계산해야함. bfs에서는 시작 노드에서 도착 노드까지의
# 최소거리임. 이 문제는 플루이드-와샬 알고리즘을 사용해야함. 검색해보고 공부하길 바람.

import sys
from collections import deque

n = int(input())
member = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
dist = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

while True:
    a, b = map(int, input().split())
    if a == -1:
        break
    member[a][b] = 1
    member[b][a] = 1

minimum = 50
for i in range(1, n + 1):
    q = []
    chk = [0 for i in range(n + 1)]
    chk[i] = 1
    q.append((i, 0))

    # bfs
    while q:
        m, cnt = q.pop(0)
        for k in range(1, n + 1):
            # 채워져 있는게 더 작을 때
            if chk[k] or member[m][k] == 0:
                continue
            chk[k] = 1
            # 얘에서 갈 수 있으면 갑니다
            dist[i][k] = cnt + 1
            q.append((k, cnt + 1))

    # 최솟값 구하기
    t = max(dist[i])
    if minimum > t:
        minimum = t

cnt = 0
res = []
for i in range(1, n + 1):
    if max(dist[i]) == minimum:
        cnt += 1
        res.append(i)

print('{0} {1}'.format(minimum, cnt))
for i in res:
    print(i, end=' ')
print('\n')
#
# def bfs(members,start):
#     l = len(members)
#     visit = [False for x in range(l)]
#     q = deque()
#     q.append(start)
#     cnt=0
#
#     while q:
#         cur = q.popleft()
#         if visit[cur] == False:
#             visit[cur] = True
#             for i in members(cur):
#                 if visit[i-1] != True:
#                     q.append(i-1)
#     print(cnt)
#
# n = int(sys.stdin.readline().rstrip())
#
# members = [[] for x in range(n)]
# while True:
#     u,v = map(int, sys.stdin.readline().rstrip().split())
#     if(u,v) == (-1,-1): break
#     members[u-1].append(v)
#     members[v-1].append(u)
#
# print(members)
# for i in range(n):
#     bfs(members,i)
