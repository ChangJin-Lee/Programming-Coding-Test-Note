# 프로그래머스 입국심사 문제랑 매우 비슷했음.
# left, right에 해당하는 arr[mid]를 비교하는게 아니라 어떠한 수를 두고 그 수가 어떠한 수 n 보다 작은지 큰지
# 보면서 left, right를 조절하는 것임. 생각보다 단순한데 스킬만 알면 쉽게 풀 수 있음.
import sys

def bin_search(nums,n):
    answer = 0
    left, right = 0, nums[-1]
    if right == 0:
        return 0
    while left<=right:

        wire = 0
        mid = (left + right) // 2
        if mid == 0:
            answer = 1
            break
        for num in nums:
            wire += num//mid
            if wire > n:
                break
        if wire >= n:
            answer = mid
            left = mid + 1
        elif wire < n:
            right = mid - 1
    return answer

k,n = map(int, sys.stdin.readline().rstrip().split())
arr = []
for _ in range(k):
    arr.append(int(sys.stdin.readline().rstrip()))
arr.sort()
print(bin_search(arr,n))