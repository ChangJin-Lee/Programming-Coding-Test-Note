import sys
P = [0 for x in range(100)]
P[0], P[1],P[2], P[3], P[4], P[5], P[6],P[7], P[8] = 1, 1, 1, 2, 2, 3, 4, 5, 7
for i in range(9,100):
    P[i] = P[i-1] + P[i-5]
t = int(sys.stdin.readline().rstrip())
for i in range(t):
    n = int(sys.stdin.readline().rstrip())
    print(P[n-1])
