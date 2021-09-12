import sys
n = int(sys.stdin.readline().rstrip())
points = []
for _ in range(n):
    points.append(list(map(int,sys.stdin.readline().rstrip().split())))
points=sorted(points)
for point in points:
    print(" ".join(map(str,point)))

