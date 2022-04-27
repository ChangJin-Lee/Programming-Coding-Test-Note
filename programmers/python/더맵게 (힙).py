# 일반 배열로 while문 시작시에 scoville.sort를 사용했는데 time complexity가 너무 컸다.
# 힙을 사용하는 문제였다. 두개를 뽑아내서 처리하고 다시 넣어주는 형태 이므로 트리까지는 생각했는데
# 힙까지는 생각이 미치지 못했던 것 같다. 암튼 이 문제는 푸는 로직 자체는 간단한데 시간초과와 효율성 테스트가
# 메인이었다.
import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)

    if len(scoville) == 1:
        if scoville[0] < K:
            answer = - 1

    while len(scoville) >= 2:
        a = heapq.heappop(scoville)
        if a > K:
            heapq.heappush(scoville, a)
            break
        b = heapq.heappop(scoville)
        a += b * 2
        heapq.heappush(scoville, a)
        answer += 1
        if len(scoville) == 1:
            if scoville[0] < K:
                answer = -1
                break
            else:
                break

    return answer

print(solution([1, 2, 3, 9, 10, 12],7)) #2