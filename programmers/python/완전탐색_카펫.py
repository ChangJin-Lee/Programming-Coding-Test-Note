# 처음 풀었을 때 시간초과 나와서 로직을 바꿔봤음. 어쨋든 100점으로 통과함.
def solution(brown, yellow):
    answer = []
    tfset = [False for x in range(yellow + 1)]
    xyset = []
    xy = brown + yellow
    for i in range(1, len(tfset)):
        if yellow % i != 0:
            for j in range(i, len(tfset), i):
                tfset[j] = True
        else:
            xyset.append(i)
    for x in xyset:
        z = False
        for y in xyset:
            if x * y == yellow:
                x, y = x + 2, y + 2
                if x * y == xy:
                    z = True
                    answer.append(max(x, y))
                    answer.append(min(x, y))
                    break
        if z == True:
            break

    # 너무 많은 비교를 하게 되니까 시간초과 나옴.
    # xyset = []
    # xy = brown + yellow
    # for i in range(int(yellow**0.5)+1):
    #     for j in range(int(yellow**0.5),yellow+1):
    #         if i*j == yellow and (i+2)*(j+2) == xy:
    #             answer.append(max(i+2,j+2))
    #             answer.append(min(i+2,j+2))
    return answer

print(solution(10,2)) ## [4, 3]
print(solution(8,1)) ## [3, 3]
print(solution(24,24)) ## [8, 6]