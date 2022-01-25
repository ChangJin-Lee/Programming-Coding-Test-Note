import sys
N = int(sys.stdin.readline().rstrip())

nums=[]
for _ in range(N):
  nums.append(int(sys.stdin.readline().rstrip()))
nums = sorted(nums)
for num in nums:
  print(num)