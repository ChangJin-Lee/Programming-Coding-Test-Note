import sys
N = int(sys.stdin.readline().rstrip())

i, cnt = 0, 0
while True:
  if "666" in str(i): cnt+=1
  if cnt==N: print(i); break
  i+=1
  