import sys
def gcd(a, b):
    while(b != 0):
        n = a%b
        a = b
        b = n
    return a
n = int(sys.stdin.readline().rstrip())
m = list(map(int,sys.stdin.readline().rstrip().split()))

for i in range(1,n):
    g = gcd(m[0],m[i])
    print("{0}/{1}".format(int(m[0]/g),int(m[i]/g)))