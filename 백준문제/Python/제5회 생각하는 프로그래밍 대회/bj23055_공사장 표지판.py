import sys
n = int(sys.stdin.readline().rstrip())
if n < 5:
    for _ in range(n):
        print("*"*n)
else:
    for i in range(n):
        for j in range(n):
            if i == 0 or i == n-1 or j ==0 or j==n-1:
                print("*",end="")
            else:
                if j ==i or j == n-1-i:
                    print("*",end="")
                else:
                    print(" ",end="")
        print()
