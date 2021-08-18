import sys
input = list(sys.stdin.readline().strip().split(" "))
count=0
for i in range(len(input)):
    if input[i] is not '':
        count=count+1
print(count)