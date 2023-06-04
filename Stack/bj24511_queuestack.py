import sys
def dynamicpop(list,i, x): # l은 식별자. 0이면 큐, 1이면 스택
    t = list[i]
    list[i] = x
    return t

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().rstrip().split()))
b = list(map(int, sys.stdin.readline().rstrip().split()))
m = int(sys.stdin.readline())
c = list(map(int, sys.stdin.readline().rstrip().split()))

for i in range(m):
    if a[0] == 0:
        x = dynamicpop(b,0,c[i])
    else:
        x = c[i]
    for j in range(1,n):
        if a[j] == 0:
            x = dynamicpop(b,j,x)
    print(x, end=" ")