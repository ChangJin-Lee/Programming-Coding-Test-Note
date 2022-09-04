# bfs를 활용하는 전형적인 문제였음.
# 2차원 배열에서 특정한 조건에 해당하는 값을
# 찾으라는 문제는 거의 무조건 bfs,dfs임.
# 헷갈렸던 부분은 밑에 주석처리 해뒀음.
from collections import deque

def bfs(places):
    row = len(places)
    col = len(places[0])
    dq = deque()
    visit = [[False for x in range(col)] for y in range(row)]
    dq.append((0, 0))
    visit[0][0] = True

    while dq:
        (x, y) = dq.popleft()
        pcnt = 0
        for (nx, ny) in [(1, 0), (0, -1), (-1, 0), (0, 1)]:
            (nx, ny) = (x + nx, y + ny)
            if 0 <= nx < col and 0 <= ny < row:
                ## 이거랑 밑에 elif 두개를
                # visit[nx][ny] == False 일때만 실행되도록
                # 처음에 짰는데 잘 생각해보면 visit[nx][ny]가 
                # True일 때도 탐색을 해야한다.
                if places[x][y] == 'O' and places[nx][ny] == 'P': 
                    pcnt += 1
                elif places[x][y] == 'P' and places[nx][ny] == 'P':
                    return 0
                if visit[nx][ny] == False:
                    visit[nx][ny] = True
                    dq.append((nx, ny))
        if pcnt >= 2:
            return 0
    return 1


def solution(places):
    answer = []
    for place in places:
        answer.append(bfs(place))
    return answer

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))
# [1, 0, 1, 1, 1]