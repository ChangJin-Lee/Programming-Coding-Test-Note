# 단순히 생각했을땐 n^2 의 시간복잡도를 가지면 될 거 같다.
def solution(phone_book):
    answer = True
    for phone_num in phone_book:
        plen = len(phone_num)
        if answer == False:
            break
        for target in phone_book:
            chk = False
            if target != phone_num:
                for i in range(plen):
                    if phone_num[i] != target[i]:
                        chk = True
                        break
            else:
                chk = True
            if chk == False:
                answer = False
                break
    return answer