# deque 사용법 잘 알아두어야함.

from collections import deque


def bfs(n, nodes, k):
    visit = [[False for x in range(n)] for y in range(n)]
    q = deque()
    q.append((k, [k]))

    while q:
        (x, networks) = q.pop()
        for i in range(n):
            if x != i:
                if nodes[x][i] == 1 and visit[x][i] == False:
                    networks.append(i)
                    q.append((i, networks))
                visit[x][i] = True
                visit[i][x] = True
    return networks


def solution(n, computers):
    answer = 0
    tmp = []
    for i in range(n):
        k = set(bfs(n, computers, i))
        if k not in tmp:
            tmp.append(k)
            answer += 1
    return answer


if __name__ == "__main__":
    print(solution(3,	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
    print(solution(3,	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
