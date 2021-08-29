import sys
i,N = 1,int(sys.stdin.readline().strip())
while 1+3*(i)*(i-1) < N: i+=1
print(i)

# 숏코딩
# print(int((int(input())/3-.1)**.5+1.5))