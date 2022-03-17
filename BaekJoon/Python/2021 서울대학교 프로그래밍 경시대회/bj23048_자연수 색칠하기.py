import sys
n = int(sys.stdin.readline().rstrip())
arr = [x for x in range(n+1)]
for i in range(2,n+1):
    if i == arr[i]:
        for j in range(i,n+1,i):
            if arr[j] >= j:
                arr[j] = i
print(len(set(arr))-1)