# visit 배열을 q 안에 넣어버리는것이 핵심이었다.

from collections import deque
def bfs(k, dungeons):
    l = len(dungeons)
    n=0
    q = deque()
    q.append([k,[]])
    while q:
        x, v = q.popleft() # x는 dungeons 의 인덱스
        for i in range(l):
            if i not in v and x >= dungeons[i][0] and x > dungeons[i][1]:
                q.append([x-dungeons[i][1], v+[i]])
            else:
                n = max(n,len(v))
    return n
def solution(k, dungeons):
    answer = bfs(k,dungeons)
    return answer

print(solution(80,[[80, 20], [50, 40], [30, 10]])) # 3