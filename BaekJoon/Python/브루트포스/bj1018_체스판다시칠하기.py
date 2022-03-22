# 취준할 때 풀이. 8x8 체스판을 선택하는 경우를 브루트포스로 선택하고
# 그 선택된 체스판을 bfs를 돌려서 색을 바꿔야하는 칸 수를 계산하자.
import sys, copy
from collections import deque
def bfs(chessboards,fx,fy):
    # print("BFS START")
    q = deque()
    visit = [[0 for x in range(8)] for x in range(8)]
    q.append((fx,fy))
    cnt = 0

    # print(1)
    # print(chessboards[0][0:2])
    # for chessboard in chessboards:
    #     print(chessboard)

    while q:
        (x,y) = q.popleft()
        for (dx,dy) in [(0,1),(1,0),(-1,0),(0,-1)]:
            (nx,ny) = (x+dx, y+dy)
            if 0<=nx<8 and 0<=ny<8 and visit[nx][ny] == 0:
                visit[nx][ny] = 1
                q.append((nx,ny))
                if chessboards[nx][ny] == chessboards[x][y]:
                    if chessboards[nx][ny] == 'W':
                        chessboards[nx][ny] = 'B'
                    elif chessboards[nx][ny] == 'B':
                        chessboards[nx][ny] = 'W'
                    cnt+=1
    # print(2)
    # for chessboard in chessboards:
    #     print(chessboard)
    # print(cnt)
    return cnt

n,m = map(int, sys.stdin.readline().rstrip().split())
chessboards = [ list(sys.stdin.readline().rstrip()) for x in range(n)]
cnt = 2501
for i in range(n-7):
    t = copy.deepcopy(chessboards[i:i+8])
    # print("T")
    # for s in t:
    #     print(s)
    for j in range(m-7):
        tt = []
        for p in range(8):
            # print(p)
            tt.append(t[p][j:j+8])
        # print(i,j,"tt")
        # for s in tt:
        #     print(s)
        ttt = copy.deepcopy(tt)
        if tt[0][0:2] == ['W','B']:
            # print("1 if")
            v1 = bfs(tt, 0, 0)
            ttt[0][0] = 'B'
            v2 = bfs(ttt, 0, 0) + 1
        elif tt[0][0:2] == ['B','W']:
            # print("2 if")
            v1 = bfs(tt,0,0)
            ttt[0][0] = 'W'
            v2 = bfs(ttt,0,0) + 1
        else:
            # print("3 if")
            v1 = bfs(tt,0,0)
            v2 = bfs(ttt,0,1)
        # print("v1,v2",v1,v2)
        v = min(v1,v2)
        if cnt > v:
            cnt = v
print(cnt)

# 학부 2학년때 풀이
# import sys
# m,n = map(int, sys.stdin.readline().rstrip().split())
# datas,cnt, countercnt= [],[], m*n
# for _ in range(m): datas.append(list(sys.stdin.readline().rstrip()))
# for p in range(m-7):
#     for q in range(n-7):
#         startP = datas[p][q]
#         # print(datas)
#         ccnt=0
#         for i in range(p,p+8,2):
#             for j in range(q,q+8,2):
#                 if datas[i][j] != startP : ccnt+=1
#             for j in range(q+1,q+8,2):
#                 if datas[i][j] == startP : ccnt+=1
#                 # print(datas[i][j],startP,cnt)
#         for i in range(p+1,p+8,2):
#             for j in range(q,q+8,2):
#                 if datas[i][j] == startP : ccnt+=1
#             for j in range(q+1,q+8,2):
#                 if datas[i][j] != startP : ccnt+=1
#                 # print(datas[i][j],startP,cnt)
#         cnt.append(min(ccnt,countercnt))
# print(min(cnt))


