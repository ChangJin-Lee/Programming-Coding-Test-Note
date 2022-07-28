from audioop import reverse
from cgitb import strong


def solution(stones, k):
    answer = 0
    state = stones[0]
    n=0
    
    for i in range(1,len(stones)):
        if stones[i] < state:
            n+=1
        else:
            n=0
            state=stones[i]
        if n==k:
            new_stones=stones[i-n+1:i+1]
            break
    print(max(new_stones))
    
    print(stones)
    for stone in stones:
        print(stone-1, end=" ")
    print("")
    for stone in stones:
        print(stone-2, end=" ")
    print("")
    for stone in stones:
        print(stone-3, end=" ")
    print("")    
    
    stones.sort(reverse=True)
    print(stones)
    for stone in stones:
        print(stone-1, end=" ")
    print("")
    for stone in stones:
        print(stone-2, end=" ")
    print("")
    for stone in stones:
        print(stone-3, end=" ")
    return answer


print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1],3))