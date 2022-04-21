# 만들 수 있는 소수의 개수를 출력하는 문제였음.
# 일단 에라토스테네스의 체로 소수를 담고 있는 배열을 만들어야 했고,
# 소수가 들어있는 배열에서 적당히 바꿔야 했음.
# 경우의 수가 많은 문제 이므로, itertools를 사용했음.
# 원래 itertools는 time complexity가 높아서 사용하면 테스트 케이스를 다 통과하지 못하는 경우가 많은데,
# 여기선 간신히 통과했음.
import itertools
def eratones(n):
    chk = [False for x in range(n)]
    primes = []
    for i in range(2,n):
        if chk[i] == False:
            primes.append(i)
            for j in range(i,n,i):
                chk[j] = True
    return primes
def solution(numbers):
    answer = []
    lnumbers = list(map(int, numbers))
    lnumbers.sort(reverse = True)
    ss = ""
    for l in lnumbers:
        ss+=str(l)
    primes = eratones(int(ss)+1)
    for i in range(1,len(lnumbers)+1):
        pnumbers = list(itertools.permutations(lnumbers,i))
        pnumbers = list(set(pnumbers))
        # print(pnumbers)
        for pnumber in pnumbers:
            ppnumber = int("".join(map(str,list(pnumber))))
            if ppnumber in primes:
                if ppnumber not in answer:
                    answer.append(ppnumber)
    return len(answer)

print(solution("17")) ## 3
print(solution("011")) ## 2