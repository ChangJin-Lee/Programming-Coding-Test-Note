import sys
M,N = int(sys.stdin.readline().rstrip()),int(sys.stdin.readline().rstrip())
prime=[]
for num in range(M,N+1):
    check=0
    for i in range(2,num):
        if num%i ==0: check=1
    if num==1: check=1
    if check==0: prime.append(num)
if prime: print(sum(prime),min(prime),sep="\n")
else: print(-1)