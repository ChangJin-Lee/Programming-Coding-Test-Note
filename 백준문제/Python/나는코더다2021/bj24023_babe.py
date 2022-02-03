import sys
N, K = map(int,sys.stdin.readline().rstrip().split())
A = list(map(int,sys.stdin.readline().rstrip().split()))
bounds = []
#print(N,K,A)
#print(bounds)
lengthofA = 0
i = 0
while True:
    if i >= N:
        break
    if A[i] | K <= K:
        lengthofA+=1
        bounds.append(i)
    else:
        if lengthofA>=2:
            break
        else:
            lengthofA=0
            bounds.clear()
    i+=1
#print(bounds)
if bounds==[] or len(bounds) == 1:
    print(-1)
else:
    print(bounds[0]+1, bounds[-1]+1)