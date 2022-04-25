# 전형적인 큐를 사용하는 문제였다.
# 인덱스값을 정할때 실수했다. 정답 조건을 잘 살펴보자.

def solution(priorities, location):
    answer, i = 0, 0
    numbers = {}
    l = len(priorities)
    docs = [x for x in range(l)]
    for k in range(l):
        numbers[k] = priorities[k]
    while i < l:
        biggerchk = False
        for j in range(i+1,l):
            if numbers[docs[i]] < numbers[docs[j]]:
                t = docs.pop(i)
                docs.append(t)
                biggerchk = True
                break
        if biggerchk == False:
            i+=1
    answer =  docs.index(location) + 1
    return answer

print(solution([2, 1, 3, 2],2)) # 1
print(solution([1, 1, 9, 1, 1, 1],0)) # 5