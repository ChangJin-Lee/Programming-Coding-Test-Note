import sys

# 경우를 생각해보면 된다. NO인 경우가 약간 헷갈릴 수 있다.
# 1. 모두 VPS인 경우. YES.
# 2. VPS 문자열 다음으로 VPS가 아닌 문자열이 오는 경우. NO.
# 3. 첫 문자열이 VPS가 아닌경우. NO.
# 4. 문자열의 0번 인덱스가 ')'인 경우 무조건 NO.

def solution(list):
    lefts, rights = 0, 0
    x = list.pop(0)
    if x == ')':
        return "NO"
    else:
        lefts += 1
    for i in range(len(list)):
        x = list.pop(0)
        if lefts == rights:
            if x == ')':
                return "NO"
            else:
                lefts += 1
        else:
            if x == '(':
                lefts += 1
            else:
                rights += 1
    if lefts == rights:
        return "YES"
    else:
        return "NO"

t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    ps = list(map(str,sys.stdin.readline().rstrip()))
    print(solution(ps))
