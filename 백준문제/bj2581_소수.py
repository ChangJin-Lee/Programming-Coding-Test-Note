# 2021/08 coding
import sys
M,N = int(sys.stdin.readline().rstrip()),int(sys.stdin.readline().rstrip())
prime=[]
for num in range(M,N):
    check=0
    for i in range(2,num):
        if num%i ==0: check=1
    if num==1: check=1
    if check==0: prime.append(num)
print(sum(prime),min(prime),sep="\n")


# 2020/11 coding
# import sys
# def isprime(n):
#     if n ==1:
#         return False
#     if n == 2:
#         return True
#     list=[False]*(n+1)
#     list[0],list[n]=True,True
#     for i in range(2,n):
#         if n%i == 0 and list[i]==False:
#             for m in range(i,n,i):
#                 list[m]=True
#     # print(list)
#     cnt=0
#     for l in range(0,n+1):
#         if list[l]==True:
#             cnt+=1
#     if cnt == 2:
#         return True
#     else:
#         return False
# cnt=0
# N = int(sys.stdin.readline().rstrip())
# temp = list(map(int,sys.stdin.readline().rstrip().split()))
# for i in range(N):
#     if isprime(temp[i]):
#         cnt+=1
# print(cnt)