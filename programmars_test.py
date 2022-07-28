# import heapq

# def solution(n, works):
#     answer = 0
#     for i in range(n):
#         j = works.index(max(works))
#         if works[j] != 0:
#             works[j]-=1
#     for work in works:
#         answer += work**2
#     return answer
# def solution(n, works):
#     answer = 0
#     for i in range(n):
#         heapq.heapify(works)
#         works[-1]-=1
#         print(works)
        
#     print(works)
#     for val in works:
#         answer += val**2
#     return answer

def solution(n, weak, dist):
    answer = 0
    for i in range(len(weak)-1,-1,-1):
        if weak[i] > n/2:
            weak[i] -= n
        else:
            break
    sums = min(weak)
    for i in range(len(weak)):
        weak[i]+=-sums
    weak.sort()
    print(weak)
    return answer

print(solution(12,[1, 5, 6, 10],[1, 2, 3, 4]))
print(solution(12,[1, 3, 4, 9, 10],[3, 5, 7]))

