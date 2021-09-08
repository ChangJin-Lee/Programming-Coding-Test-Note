import sys
m,n = map(int, sys.stdin.readline().rstrip().split())
datas,cnt, lock = [],0, False
for _ in range(m): datas.append(list(sys.stdin.readline().rstrip()))
for p in range(m-7):
    for q in range(n-7):
        startP = chess[p][q]
        print(chess)
        
print(cnt)