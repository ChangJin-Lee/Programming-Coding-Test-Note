import sys
x, y,cx,cy = [],[], 0,0
for _ in range(3):
    a,b = map(int,sys.stdin.readline().rstrip().split())
    x.append(a); y.append(b)
for i in range(3):
    if x.count(x[i]) == 1 : cx = x[i]
    if y.count(y[i]) == 1 : cy = y[i]
print(cx,cy,sep=" ")


