import sys
input = list(map(str, sys.stdin.readline().split()))
count=0
for i in range(len(input)):
    if input[i]!='':
        count=count+1
print(count)

# sentence = list(map(str,input().split()))
#
# print(len(sentence))