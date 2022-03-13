import sys
# # exclusive or는 NAND와 OR를 AND한 결과이다.
# def xor(a,b):
#     t1 = ~(a & b)
#     t2 = a|b
#     return t1&t2
n, k = map(int,sys.stdin.readline().rstrip().split())
A = list(map(int,sys.stdin.readline().rstrip().split()))
bounds = [0 for x in range(n)]
for i in range(n):
    if A[i] >= k:
        bounds[i] = 1
check = False
for i in range(n):
    section = A[i]
    if bounds[i] == 0:
        for j in range(i+1,n):
            section = section | A[j]
            if section == k:
                print(i+1,j+1)
                check = True
                break
            elif section > k:
                break
    if check == True: break
if check == False: print(-1)


# bounds = []
# lengthofA = 0
# i = 0
# while True:
#     if i >= N:
#         break
#     if A[i] | K <= K:
#         lengthofA+=1
#         bounds.append(i)
#     else:
#         if lengthofA>=2:
#             break
#         else:
#             lengthofA=0
#             bounds.clear()
#     i+=1
# #print(bounds)
# if bounds==[] or len(bounds) == 1:
#     print(-1)
# else:
#     print(bounds[0]+1, bounds[-1]+1)