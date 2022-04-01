# 문제를 꼼꼼하게 읽자.
# 잘 보면 단 한 명의 선수만 들어오지 못했으니, participant와 completion은 길이의 차가
# 정확히 1이다. sort를 하면 더 쉬워지는 것임.

def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()

    for i in range(len(completion)):
        if participant[i] != completion[i]:
            answer = participant[i]
            break
        else:
            answer = participant[-1]

    # i = 0
    # while(True):
    #     if completion == []:
    #         break
    #     participant.remove(completion[i])
    #     completion.pop(i)

    # for i in range(len(participant)):
    #     for j in range(len(completion)):
    #         if participant[i] == completion[j]:
    #             participant[i],completion[j] = "",""
    # answer = "".join(str(x) for x in participant)
    return answer