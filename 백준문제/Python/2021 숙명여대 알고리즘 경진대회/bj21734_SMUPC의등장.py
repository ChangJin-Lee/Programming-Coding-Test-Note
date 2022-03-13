import sys
S = list(sys.stdin.readline().rstrip())
for z in S:
    k = ord(z)
    k = str(k)
    k = [int(x) for x in k]
    for _ in range(sum(k)):
        print(z,end="")
    print()