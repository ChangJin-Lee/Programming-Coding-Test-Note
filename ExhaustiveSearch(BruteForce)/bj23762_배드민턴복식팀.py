import sys

n = int(sys.stdin.readline().rstrip())
ability = list(map(int,sys.stdin.readline().rstrip().split()))
w = []

for i in range(n):
    target = ability[i]
    weight = 0
    for j in range(n):
        weight += target - ability[j]
    w.append(weight)

print(w)