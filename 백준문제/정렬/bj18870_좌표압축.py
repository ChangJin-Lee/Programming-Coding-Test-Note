# 일반적으로 index를 써서 푸는 방법을 생각할텐데, 그건 시간복잡도가 O(N^2)임.
# 딕셔너리를 써야 O(N) 시간 안에 해결 가능함.
import sys
n = int(sys.stdin.readline().rstrip())
xs = list(map(int,sys.stdin.readline().rstrip().split()))
sorted_xs=sorted(set(xs))
dic = {}
for i in range(len(sorted_xs)):
    dic[sorted_xs[i]] = i
# sorted_dic = sorted(dic.items(), key = lambda x:(x[1]))
for x in xs:
    print(dic[x], end=" ")

# for i in range(n):
#     print(sortedxs.index(xs[i]),end=" ")