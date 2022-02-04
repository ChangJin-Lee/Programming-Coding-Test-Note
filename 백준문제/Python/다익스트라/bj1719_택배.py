# import sys
#
# n,m = map(int,sys.stdin.readline().rstrip().split())
#
# graph = [[] for j in range(n+1)]
# result = [[] for k in range(n+1)]
#
# for i in range(m):
#     a, b, c = map(int,sys.stdin.readline().rstrip().split())
#     graph[a].append((b,c))
#
# for p in graph:
#     print(p)
#
# # 방문 체크
# visited = [False]*(n+1)
# # 최단거리 테이블
# distance = [1001]*(n+1)
#
# # 방문하지 않은 노드 중 가장 최단거리가 짧은 노드의 번호를 반환
# def get_smallest_node():
#   min_value = 1001
#   index = 0
#   for i in range(1, n+1):
#     if distance[i] < min_value and not visited[i]:
#       min_value = distance[i]
#       index = i
#   return index
#
# # 다익스트라 알고리즘
# def dijkstra(start):
#     print("in")
#     # 시작 노드
#     distance[start] = 0
#     visited[start] = True
#     # 출발노드와 인접노드에 대해 최단거리 테이블 갱신
#     for j in graph[start]:
#         distance[j[0]] = j[1]
#
#     # 모든 노드에 대해 반복
#     for i in range(n - 1):
#         # 현재 최단거리가 가장 짧은 노드를 꺼내서 방문처리
#         now = get_smallest_node()
#         visited[now] = True
#         print(now)
#         # 선택된 노드와 연결된 다른 노드를 확인
#         for j in graph[now]:
#             # 선택된 노드를 통해 가는 비용을 다시 계산
#             # 선택된 노드의 비용 + 연결된 노드로 가는 비용
#             cost = distance[now] + j[1]
#             # 선택된 노드를 거쳐서 가는 비용이 더 짧은 경우
#             print("dijkstra")
#             print(j[0], j[1], cost)
#             if cost < distance[j[0]]:
#                 distance[j[0]] = cost  # 최단거리 테이블 갱신
#
#
#
# # 다익스트라 알고리즘수행
# for i in range(1,n+1):
#     dijkstra(i)
#     # 모든 노드로 가기 위한 최단 거리를 출력
#     for j in range(1, n+1):
#   # 도달할 수 없는 경우
#         if distance[j] == 1001:
#             print("infinity", end=" ")
#         else:
#             print(distance[j], end=" ")
#     print("\n")


# 다익스트라 알고리즘을 모든 집하장에 대해 실행하고,
# 맨 처음 방문하는 집하장을 경로표에 모은다.

import sys

input = sys.stdin.readline


def Dijkstra(G, s, n):
    visited = [0 for i in range(n + 1)]
    dist = [float('inf') for i in range(n + 1)]
    parents = ['-' for i in range(n + 1)]
    dist[s] = 0

    for i in range(1, n + 1):
        minidx, minval = -1, float('inf')
        for j in range(1, n + 1):
            if not visited[j] and dist[j] < minval:
                minidx = j
                minval = dist[j]
        visited[minidx] = 1

        if G.get(minidx):
            for v, val in G.get(minidx):
                if not visited[v] and dist[minidx] + val < dist[v]:
                    dist[v] = dist[minidx] + val
                    parents[v] = minidx
                    if minidx == s: parents[v] = v

    for i in range(1, n + 1):
        if i == s: continue
        arrive = parents[i]
        while not parents[arrive] == arrive:
            arrive = parents[arrive]
        parents[i] = arrive

    return parents[1:]


n, m = map(int, input().split())
graph = dict()
result = []

for i in range(m):
    s, e, t = map(int, input().split())
    if graph.get(s):
        graph.get(s).append((e, t))
    else:
        graph[s] = [(e, t)]
    if graph.get(e):
        graph.get(e).append((s, t))
    else:
        graph[e] = [(s, t)]

for i in range(1, n + 1):
    result.append(Dijkstra(graph, i, n))

for _ in range(n):
    print(*result[_])