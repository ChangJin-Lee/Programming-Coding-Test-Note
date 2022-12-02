def solution(rows, columns, queries):
    answer = []
    arr = [[1+x + rows*y for x in range(columns)] for y in range(rows)]
    print(arr)
    print(arr[1][2])
    for query in queries:
        tmin = rows*columns
        [x1, y1, x2, y2] = query
        temp = arr[x1-1][y1-1]
        if temp < tmin:
            tmin = temp
        # right
        for i in range(y1, y2):
            ntemp = arr[x1-1][i]
            arr[x1-1][i] = temp
            temp = ntemp
            if temp < tmin:
                tmin = temp
        # down
        for i in range(x1, x2):
            ntemp = arr[i][y2-1]
            arr[i][y2-1] = temp
            temp = ntemp
            if temp < tmin:
                tmin = temp
        # print(temp, arr[x2-1][y2-1])
        # left
        for i in range(y2-2, y1-2, -1):
            ntemp = arr[x2-1][i]
            arr[x2-1][i] = temp
            temp = ntemp
            if temp < tmin:
                tmin = temp
        # print(temp, arr[x2-1][y1-1])
        # up
        for i in range(x2-2, x1-1, -1):
            ntemp = arr[i][y1-1]
            arr[i][y1-1] = temp
            temp = ntemp
            if temp < tmin:
                tmin = temp
        arr[x1-1][y1-1] = temp
        answer.append(tmin)
    return answer


print(solution(6, 6, [[2, 2, 5, 4], [3, 3, 6, 6], [5, 1, 6, 3]]))  # [3, 5]))
# [1, 6]))
print(solution(3, 3, [[1, 1, 2, 2], [1, 2, 2, 3], [2, 1, 3, 2], [2, 2, 3, 3]]))
print(solution(100, 97, [[1, 1, 100, 97]]))  # [1, 1]))
print(solution(2, 6, [[1, 1, 2, 3]]))  # [1, 1]))
