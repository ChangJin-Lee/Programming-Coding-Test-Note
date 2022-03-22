import sys
n = int(sys.stdin.readline().rstrip())
points = []
for i in range(n):
    values = list(map(str,sys.stdin.readline().rstrip().split()))
    if values not in points:
        points.append(values)

for i in range(len(points)):
    points[i].append(len(points[i][0]))

# sorted의 key인자를 공부하자.
# lambda 뒤에 x[1]은 points[1]를 기준으로 먼저 오름차순 정렬하고
# 그 뒤에 있는 x[0]은 나머지는 points[0]을 기준으로 오름차순 정렬하겠다는 이야기임.
# 그리고 내림차순으로 정렬하려면 -x[1] 이렇게 적어주면 됨.
points=sorted(points, key= lambda x: (x[1],x[0]))
for point in points:
    print(point[0])

