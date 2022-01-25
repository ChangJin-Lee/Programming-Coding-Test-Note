import sys
n=int(sys.stdin.readline())
frequency = [0]*8001
for i in range(n):
  x = int(sys.stdin.readline())
  frequency[4000+x]+=1
temp=[]
for i in range(8001):
  if frequency[i]!=0:
    for j in range(frequency[i]):
      temp.append(i-4000)

# 산술평균
average = round(sum(temp)/n)
#중간값
mean = temp[int(n/2)]
#최빈값
frecnt = frequency.count(max(frequency))
freindex = frequency.index(max(frequency))
mode = freindex-4000
if frecnt>1:
  k = temp.index(freindex-4000)
  o = temp[k]
  for i in range(len(temp)):
    if o != temp[i] and temp.count(o) == temp.count(temp[i]) : mode = temp[i]; break
#범위
range = temp[n-1] - temp[0]

print(average, mean, mode, range, sep="\n")



