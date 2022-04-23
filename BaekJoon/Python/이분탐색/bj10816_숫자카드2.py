import sys

def bin_search(arr,target):
    left, right = 0, len(arr)-1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] > target:
            right = mid - 1
        elif arr[mid] < target:
            left = mid + 1
        elif arr[mid] == target:
            return True
    return False

n = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().rstrip().split()))
m = int(sys.stdin.readline())
targets = list(map(int, sys.stdin.readline().rstrip().split()))

cards = {}
for number in numbers:
    if number in cards.keys():
        cards[number] += 1
    else:
        cards[number] = 1
numbers = list(set(numbers))
numbers.sort()
for target in targets:
    if bin_search(numbers,target) == True:
        print(cards[target])
    else:
        print(0)