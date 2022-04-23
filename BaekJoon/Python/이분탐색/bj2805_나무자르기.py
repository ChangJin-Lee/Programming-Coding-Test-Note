# 나무 자르기 문제였음. 통과하지 못하는 test cases가 있다면 left, right의 값을 잘 확인하고
# wood의 개수는 잘 계산했는지 등을 확인해봐야함.

import sys

def bin_search(heights,m):
    left, right = 0,heights[-1]
    answer = 0

    while left<=right:
        mid = (left + right) // 2
        wood = 0
        for height in heights:
            diff = height - mid
            if diff > 0:
                wood += diff
                if wood > m:
                    break

        if wood >=m:
            answer = mid
            left = mid + 1
        elif wood < m:
            right = mid - 1
    return answer

n,m = map(int, sys.stdin.readline().rstrip().split())
Heights = list(map(int, sys.stdin.readline().rstrip().split()))
Heights.sort()
print(bin_search(Heights,m))