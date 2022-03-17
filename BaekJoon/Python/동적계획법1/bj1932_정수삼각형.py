import sys
n = int(sys.stdin.readline().rstrip())
nums = []

for _ in range(n):
    num = list(map(int,sys.stdin.readline().rstrip().split()))
    nums.append(num)

if n ==1:
    print(nums[0][0])
else:
    nums[1][0] += nums[0][0]
    nums[1][1] += nums[0][0]
    for i in range(2,len(nums)):
        nums[i][0] += nums[i-1][0]
        nums[i][-1] += nums[i-1][-1]
        for j in range(1,len(nums[i])-1):
            choicenum = max(nums[i-1][j-1],nums[i-1][j])
            nums[i][j]+=choicenum
    print(max(nums[-1]))