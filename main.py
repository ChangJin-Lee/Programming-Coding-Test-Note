A  = [5,1,3,7]
B = [2,2,6,6]	
answer = 0
focustable = []
A.sort(reverse=True)
B.sort(reverse=True)
print(A,B)

for i in range(len(A)):
    if A[i] < B[i]:
        answer += 1
    elif A[i] > B[i]:
        for j in range(i+1,len(A)):
            if A[j] > B[j] and A[j] < B[i]:
                B[i],B[j] = B[j],B[i]
                break
print(A,B)
print(answer)