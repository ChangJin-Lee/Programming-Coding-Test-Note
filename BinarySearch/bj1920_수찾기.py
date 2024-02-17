# 이분탐색을 이용한 풀이임.
# 전체적인 로직은 어느정도 외운거 같은데 아직 변형하는건 익숙하지 않음.

import sys

def bin_search(arr, m):
    temp = ""
    left, right = 0, len(arr)-1 # 이 부분에서 처음에 arr[0], arr[-1]로 생각했음. 이분탐색은 인덱스를 left, right로 놔야하는거 같음.

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] > m:
            right = mid-1
        elif arr[mid] < m:
            left = mid+1
        elif arr[mid] == m:
            return 1
    return 0

n = sys.stdin.readline().rstrip()
arr = list(map(int, sys.stdin.readline().rstrip().split()))
m = sys.stdin.readline().rstrip()
targets = list(map(int, sys.stdin.readline().rstrip().split()))

arr.sort()

for target in targets:
    print(bin_search(arr,target))
