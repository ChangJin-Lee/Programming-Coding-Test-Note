import sys

def checkwires(dp, wires):
    for i in range(len(dp)):
        wires[i] = 0
        A, B = dp[i][0], dp[i][1]
        for j in range(len(dp)):
            if dp[j][0] > A and dp[j][1] < B or dp[j][0] < A and dp[j][1] > B:
                wires[i]+=1
    for wire in wires:
        if wire != 0:
            return 1

def deletewire(dp,wires):
    cnt=0
    j = wires.count(max(wires))
    for i in range(j):
        target = wires.index(max(wires))
        wires.pop(target)
        dp.pop(target)
        cnt+=1
    return cnt
n = int(sys.stdin.readline().rstrip())
dp = [[0 for i in range(2)] for j in range(101)]
wires = [0 for k in range(101)]

for i in range(n):
    dp[i][0] , dp[i][1] = list(map(int, sys.stdin.readline().rstrip().split()))

cnt = 0
checkwires(dp,wires)
for i in range(n):
    if checkwires(dp, wires) == 1 :
        print(dp)
        print(wires)
        print(cnt)
        cnt+=deletewire(dp,wires)

print("dddd")
print(cnt)

#
# print(checkCross(dp,wires))
# print(dp,wires)
# deletewire(dp,wires)
# print(dp,wires)
# 1. 제일 많이 교차하고 있는 