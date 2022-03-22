import sys, copy

def ps(list):
    small_left_char, small_right_char = '(', ')'
    big_left_char, big_right_char = '(', ')'
    big_left_cnt, big_right_cnt, small_left_cnt, small_right_cnt = 0, 0, 0, 0
    while True:
        x = list.pop(0)
        if x == small_left_char or x == big_left_char or x == small_right_char or x == big_right_char:
            break
        elif x == '.': return True
    if x == small_right_char or x == big_right_char:
        return False
    elif x== small_left_char:
        small_left_cnt += 1
    elif x == big_left_char:
        big_left_cnt += 1
    for i in range(len(list)):
        x = list.pop(0)
        if x == small_left_char or x == small_right_char:
            if small_left_cnt != 0 and small_right_cnt != 0 and small_left_cnt == small_right_cnt:
                if x == small_right_char or big_left_cnt != big_right_cnt:
                    return False
                elif x == small_left_char:
                    small_left_cnt += 1
            elif small_left_cnt != small_right_cnt:
                if x == small_left_char:
                    small_left_cnt += 1
                else:
                    small_right_cnt += 1
    if lefts == rights:
        return True
    else:
        return False

def solution(list):
    temp = copy.deepcopy(list)
    if ps(temp):
        return "yes"
    else:
        return "no"

def exit(char):
    if char == '.':
        return True
    else:
        return False

while True:
    input = list(map(str,sys.stdin.readline().rstrip()))
    print(input)
    if exit(input[0]): break
    print(solution(input))