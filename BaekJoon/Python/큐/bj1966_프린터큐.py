import sys
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
n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    t, location = map(int, sys.stdin.readline().rstrip().split())
    priorities = list(map(int,sys.stdin.readline().rstrip().split()))
    print(solution(priorities,location))