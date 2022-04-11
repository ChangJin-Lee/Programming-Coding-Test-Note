# 사이트에서 2,3,7번 케이스가 통과를 못한다 이유가 뭘까?

def solution(s):
    slen = len(s)
    answer = slen
    for d in range(1,slen):
        zips = {}
        t = slen
        for i in range(0,slen-d,d):
            if s[i:i+d] == s[i+d:i+2*d]:
                if s[i:i+d] not in zips.keys():
                    zips[s[i:i+d]] = 2
                else:
                    zips[s[i:i+d]] += 1
                t-=d
        shorted = 0
        for zip in zips.values():
            shorted += len(str(zip))
        t+=shorted
        if answer >= t:
            answer = t
    return answer

print(solution("acdhdh")) # 5
print(solution("xztjabcdabcd")) # 12
print(solution("abcabcabcabcdededededede")) # 14
print(solution("ababcdcdababcdcd")) # 9
print(solution("aabbaccc")) #7
print(solution("aaaaaaaaaaaabcd")) #6
print(solution("xxxxxxxxxxyyy")) #5