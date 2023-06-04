def solution(lottos, win_nums):
    answer = []
    score_dict = {
        6: 1,
        5: 2,
        4: 3,
        3: 4,
        2: 5,
        1: 6,
        0: 6
    }
    highest_score, zero_counts = 0, 0
    for lotto in lottos:
        if lotto in win_nums:
            highest_score += 1
        elif lotto == 0:
            zero_counts += 1
    answer.append(score_dict[highest_score+zero_counts])
    answer.append(score_dict[highest_score])
    return answer


print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))  # [3, 5]))
print(solution([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]))  # [1, 6]))
print(solution([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]))  # [1, 1]))
