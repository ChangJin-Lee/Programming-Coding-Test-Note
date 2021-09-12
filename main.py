import sys
n=int(sys.stdin.readline())
nums = [0]*4000
for i in range(n):
  x = int(sys.stdin.readline())
  nums[x]+=1

# 산술평균 
average = round(sum(nums)/n)
#중간값
mean = nums[int(n/2)]
#최반값
mode = nums.index(max(nums))
#범위
range = nums[n-1] - nums[0]

print(average, mean, mode, range, sep="\n")