import sys
m,n = map(int, sys.stdin.readline().rstrip().split())
datas, cnt = [], m*n
for _ in range(m): datas.append(list(sys.stdin.readline().rstrip()))
for p in range(m-7):
    for q in range(n-7):
        startP = datas[p][q]
        # print(datas)
        ccnt=0
        for i in range(p,p+8,2):
            for j in range(q,q+8,2):
                if datas[i][j] != startP : ccnt+=1
            for j in range(q+1,q+8,2):
                if datas[i][j] == startP : ccnt+=1
                # print(datas[i][j],startP,cnt)
        for i in range(p+1,p+8,2):
            for j in range(q,q+8,2):
                if datas[i][j] == startP : ccnt+=1
            for j in range(q+1,q+8,2):
                if datas[i][j] != startP : ccnt+=1
                # print(datas[i][j],startP,cnt)
        if ccnt < cnt : cnt = ccnt
print(cnt)