import sys
s = sys.stdin.readline().rstrip()
S = [x for x in s]
for z in S:
    k = ord(z)
    k = str(k)
    k = [int(x) for x in k]
    for _ in range(sum(k)):
        print(z,end="")
    print()