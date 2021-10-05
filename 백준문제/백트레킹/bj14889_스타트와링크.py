# 메모리 초과의 원인.
# 1. i,j 인덱스를 돌리는 for문에서 불필요한 반복이 있었음.
# 2. append보다 [x for x in range(n)] 이게 더 빠른거 같음.
# 3. 집합이 조금 더 가벼움. 집합을 사용하셈
import sys, itertools
n = int(sys.stdin.readline().rstrip())
halfn = int(n/2)
s,combi=[],[]
for _ in range(n):
    s.append(list(map(int,sys.stdin.readline().rstrip().split())))

combi = [x for x in range(n)]

teams = list(itertools.combinations(combi,halfn))

# print(teams)

min = 9999999
for team in teams:
    start, link = 0,0
    anotherteam = list(set(combi) - set(list(team)))
    # print(team)
    # print(anotherteam)
    for i in range(halfn):
        for j in range(i+1,halfn):
                start += s[team[i]][team[j]] + s[team[j]][team[i]]
                link += s[anotherteam[i]][anotherteam[j]] + s[anotherteam[j]][anotherteam[i]]
    if min > abs(start - link):
        min = abs(start-link)

# print(result)
print(min)
