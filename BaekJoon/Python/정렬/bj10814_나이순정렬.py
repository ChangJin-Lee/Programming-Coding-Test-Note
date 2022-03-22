import sys
n = int(sys.stdin.readline().rstrip())
points = []
for i in range(n):
    value1,value2 = map(str,sys.stdin.readline().rstrip().split())
    points.append([int(value1)])
    points[i].append(value2)
    points[i].append(int(i))

points=sorted(points, key= lambda x: (x[0], x[2]))
for point in points:
    print(point[0],point[1])

