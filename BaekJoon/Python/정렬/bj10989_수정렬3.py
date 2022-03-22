# n의 수가 매우큼. 같은 수가 나올 빈도가 매우 높기때문에 빈도를 저장하자. 다행히 수의 범위가 적다.
import sys
n=int(sys.stdin.readline())

# 계수정렬
frequency = [0]*10001
for _ in range(n):
    i = int(sys.stdin.readline())
    frequency[i] += 1

for i in range (10001): #0~10000
    if frequency[i]!=0:
        for j in range(frequency[i]):
            print(i)