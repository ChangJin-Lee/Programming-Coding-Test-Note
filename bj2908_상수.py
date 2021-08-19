import sys
input = list(map(str,sys.stdin.readline().rstrip().split()))
for i in range(len(input)): input[i] = int(''.join(list(reversed(input[i]))))
print(max(input))