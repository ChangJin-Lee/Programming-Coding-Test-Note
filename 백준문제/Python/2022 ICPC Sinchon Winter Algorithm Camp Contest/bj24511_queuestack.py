import sys
def dynamicpop(list,i, x, l): # l은 식별자. 0이면 큐, 1이면 스택
    if l == 1:
        return x
    else:
        t = list[i]
        list[i] = x
        return t

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().rstrip().split()))
b = list(map(int, sys.stdin.readline().rstrip().split()))
m = int(sys.stdin.readline())
c = list(map(int, sys.stdin.readline().rstrip().split()))

for i in range(m):
    x = dynamicpop(b,0,c[i],a[0])
    for j in range(1,n):
        x = dynamicpop(b,j,x,a[j])
    print(x, end=" ")