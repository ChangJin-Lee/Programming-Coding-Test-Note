# 문제 괜찮음.
# 트리로만 푸는건줄 알았는데 bfs로 풀어야 했음.
import sys
from collections import deque
input = sys.stdin.readline

def solution(N,tree):
    q = deque()
    q.append(1)
    parent = [0 for x in range(N+1)]
    while q:
        node = q.popleft()
        for i in tree[node]:
            if parent[i] == 0 and i != 1:
                parent[i] = node
                q.append(i)
    for i in range(2,N+1):
        print(parent[i])

N = int(input())
tree = dict()
for i in range(1,N+1):
    tree[i] = []
for _ in range(N-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)
solution(N,tree)



# tree={}
# n = int(sys.stdin.readline().rstrip())
# parent = [0 for x in range(n+1)]
# tree[1] = [True]
# for i in range(2,n+1):
#     tree[i] = [False]
# # print(tree)
# for i in range(n-1):
#     u,v = map(int,sys.stdin.readline().rstrip().split())
#     if False in tree[u] and False in tree[v]:
#
#     elif True in tree[u]:
#         tree[u].append(v)
#         tree[v][0] = True
#         parent[v] = u
#     elif True in tree[v]:
#         tree[v].append(u)
#         tree[u][0] = True
#         parent[u] = v
# for i in range(2,n+1):
#     print(parent[i])
