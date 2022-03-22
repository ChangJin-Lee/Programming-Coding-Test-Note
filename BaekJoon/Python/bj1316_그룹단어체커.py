# 해당하는 조건만 보면 되는 문제였음.
import sys
N = int(sys.stdin.readline())
cnt=0
for _ in range(N):
  word = sys.stdin.readline().rstrip()
  buffer= [word[0]]
  chk = False
  for i in range(1,len(word)):
    if word[i] != word[i-1] and word[i] in buffer : chk = True
    else: buffer.append(word[i])
  # print(word,buffer, chk)
  if not chk : cnt+=1
print(cnt)