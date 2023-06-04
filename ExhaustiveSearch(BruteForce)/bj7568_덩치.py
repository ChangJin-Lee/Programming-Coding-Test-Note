import sys
N = int(sys.stdin.readline().rstrip())
# h 키 w 체중
hdatas,wdatas=[],[]
for _ in range(N):
    h,w = map(int,sys.stdin.readline().rstrip().split())
    hdatas.append(h); wdatas.append(w)
cycle = len(hdatas)
for i in range(cycle):
    cnt=1
    for k in range(cycle):
        if hdatas[i] < hdatas[k] and wdatas[i] < wdatas[k] : cnt+=1
    print(cnt)

