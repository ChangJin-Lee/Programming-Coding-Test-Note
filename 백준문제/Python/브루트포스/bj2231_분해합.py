import sys
N = int(sys.stdin.readline().rstrip())
z=0
for i in range(N):
    k = list(map(int,str(i)))
    m = sum(k)+i
    if m == N: print(i); z=1; break
if z==0: print(0)