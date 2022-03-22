import sys
input = list(sys.stdin.readline().rstrip())
for i in range(97,123):
    if chr(i) not in input:
        print(-1,end=" ")
    else:
        print(input.index(chr(i)),end=" ")