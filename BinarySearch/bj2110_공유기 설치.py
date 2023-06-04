# 복습요망
# c분 탐색이 아닌가라고 생각할 수 있는데, 정답이 x보다 큰가? 정답이 x보다 작은가? 이 두개의 물음으로
# 정답을 찾을 수 있다면 이분 탐색으로 풀어낼 수 있음.
import sys

def bin_search(homes, c):
    left, right = 0, homes[-1] - homes[0]
    result = 1
    while left <= right:
        mid = (left + right) // 2
        index = 0
        count = 1
        for i in range(len(homes)):
            if (homes[i] - homes[index]) >= mid:
                index = i
                count += 1
        if count >= c:
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    return result

n,c = map(int, sys.stdin.readline().rstrip().split())
homes = []
for _ in range(n):
    homes.append(int(sys.stdin.readline().rstrip()))
homes.sort()
print(bin_search(homes, c))