import sys
while True:
    n,m = map(int, sys.stdin.readline().rstrip().split())
    if n == 0 and m == 0:
        break
    if m%n == 0:
        print("factor",end="\n")
    elif n%m == 0:
        print("multiple",end="\n")
    else:
        print("neither",end="\n")