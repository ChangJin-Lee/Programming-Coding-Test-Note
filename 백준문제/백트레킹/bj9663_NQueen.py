import sys
def placepeace(list,n,m):
  list[n][m]=1
  list[n-1][m-1]=1
n = int(sys.stdin.readline().rstrip())
chess = [[0 for i in range(n)]for j in range(n)]
print(chess)

