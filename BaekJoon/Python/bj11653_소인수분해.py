import sys
N = int(sys.stdin.readline().rstrip())
prime=[]
for num in range(2,N+1):
    check=0
    for i in range(2,num):
        if num%i ==0: check=1
    if num==1: check=1
    if check==0: prime.append(num)
for i in range(len(prime)):
    while N % prime[i] == 0:
                N = N / prime[i]; print(prime[i])