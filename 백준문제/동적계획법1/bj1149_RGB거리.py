import sys
n = int(sys.stdin.readline().rstrip())
index = -1
rgbs, result = [], []
for _ in range(n):
    rgb = list(map(int, sys.stdin.readline().rstrip().split()))
    rgbs.append(rgb)

for i in range(len(rgbs)):
    tempindex = rgbs[i].index(min(rgbs[i]))
    if tempindex != index:
        result.append(rgbs[i][tempindex])
    else:
        result.pop(-1)
        rgbs[i - 1][index] = 1001
        index = rgbs[i - 1].index(min(rgbs[i - 1]))
        result.append(rgbs[i - 1][index])
        result.append(rgbs[i][tempindex])
        # if rgbs[i][tempindex] < rgbs[i-1][index]:
        #     result.pop(-1)
        #     rgbs[i-1][index] = 1001
        #     index = rgbs[i-1].index(min(rgbs[i-1]))
        #     result.append(rgbs[i-1][index])
        #     result.append(rgbs[i][tempindex])
        # else:
        #     rgbs[i][tempindex] = 1001
        #     tempindex = rgbs[i].index(min(rgbs[i]))
        #     result.append(rgbs[i][tempindex])
    print(tempindex,result)
    index = rgbs[i].index(min(rgbs[i]))

print(sum(result))