# 우선순위 큐를 사용해 최댓값, 최소값을 계속해서 삭제하는 연산을 해야했다.
# 하나의 큐를 선언해서 사용하려고 했는데, max큐를 min큐로 바꾸는게 두 개의 큐를 선언하는것보다
# time complexity가 높아서 그냥 큐 두개를 선언해서 사용했다.
import heapq
def solution(operations):
    answer = []
    maxq,minq = [], []
    icnt, dcnt = 0, 0
    heapq.heapify(maxq)
    heapq.heapify(minq)
    for operation in operations:
        op = list(operation.split())
        op[1] = int(op[1])
        if op[0] == "I":
            heapq.heappush(maxq,-op[1])
            heapq.heappush(minq,op[1])
            icnt += 1
        elif op[0] == "D":
            if op[1] == -1:
                if minq != []:
                    heapq.heappop(minq)
            elif op[1] == 1:
                if maxq != []:
                    heapq.heappop(maxq)
            dcnt += 1
        if dcnt >= icnt:
            maxq,minq = [], []
            icnt, dcnt = 0, 0
            heapq.heapify(maxq)
            heapq.heapify(minq)
    if maxq == [] or minq == []:
        answer.append(0)
        answer.append(0)
    else:
        answer.append(-heapq.heappop(maxq))
        answer.append(heapq.heappop(minq))
    return answer
# [-3, 5, 7, 8 , 10, 32]
# [-32, -10, -8, -7, -5, 3]

# [123]
# [123]

#[0,0]
print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]))
#[333, -45]
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))