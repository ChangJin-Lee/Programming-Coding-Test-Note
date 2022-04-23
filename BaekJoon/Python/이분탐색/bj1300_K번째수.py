# 간단한데 생각할 거리가 많은 문제임.
# mid 까지의 개수를 계산하는 방법에 대해 잘 생각을 해보아야함.
import sys

def bin_search(k,n):
    result = 0
    left, right = 1, n*n

    while left <= right:
        mid = (left + right) // 2
        cnt = 0

        for i in range(1, n+1):
            cnt += min(mid//i , n) # 이거 결국엔 좌변과 우변을 똑같이 i 로 나눈것과 같음.
            # 예를들면 1,2,3,4    2,4,6,8    3,6,8,10 일때 i=2, i=3 이면 i=1일때와 똑같은 형태를 만들으려고 하는거임. 그래야 개수를 셀수있음.

        if cnt >= k:
            right = mid - 1
            result = mid
        elif cnt < k:
            left = mid + 1
    return result

n = int(sys.stdin.readline().rstrip())
k = int(sys.stdin.readline().rstrip())
print(bin_search(k,n))