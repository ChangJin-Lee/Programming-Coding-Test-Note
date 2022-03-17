import sys

N = int(sys.stdin.readline())
A = list(map(str,sys.stdin.readline().split()))
B = list(map(str,sys.stdin.readline().split()))


for i in range(len(A)):
    for j in range(len(A)):
        # case 1. trade 2 people
        if A[i] == B[j] and A[j] == B[i]:
            A[i], A[j] = A[j], A[i]
        # case 2. tade 3 people
print(A,B)
