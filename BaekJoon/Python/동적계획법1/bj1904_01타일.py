import sys
N= int(sys.stdin.readline())

arrs=[0]*(N+2)
arrs[1]=1
arrs[2]=2

for i in range(1,N-1):
    arrs[i+2]=(arrs[i]+arrs[i+1])%15746
print(arrs[N]%15746)