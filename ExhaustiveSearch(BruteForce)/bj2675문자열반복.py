import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    input = list(sys.stdin.readline().rstrip().split(" "))
    for i in range(len(input[1])): print(input[1][i]*int(input[0]),end="")
    print("")