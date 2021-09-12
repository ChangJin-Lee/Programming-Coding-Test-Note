import sys
n=int(sys.stdin.readline())
nums = []
for i in range(n):
  x = int(sys.stdin.readline())
  nums.append(x)
nums = sorted(nums)

# 산술평균
average = round(sum(nums)/n)
#중간값
mean = nums[int(n/2)]빈
#최값
mode = nums.index(max(nums))
#범위
range = nums[n-1] - nums[0]

print(average, mean, mode, range, sep="\n")