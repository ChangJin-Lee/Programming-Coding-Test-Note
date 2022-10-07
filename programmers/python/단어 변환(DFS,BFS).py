from collections import deque
import copy


def match(standard, target):
    cnt = 0
    for s1, s2 in zip(standard, target):
        if s1 != s2:
            cnt += 1
    if cnt == 1:
        return True
    return False


def match(standard, target):
    cnt = 0
    for s1, s2 in zip(standard, target):
        if s1 != s2:
            cnt += 1
    if cnt == 1:
        return True
    return False


def solution(begin, target, words):
    answer = 0
    posibility = []
    if target in words:
        q = deque()
        for word in words:
            if match(begin, word) == True:
                q.append([begin, word])
        while q:
            element = q.pop()
            if element[-1] == target:
                posibility.append(element)
            else:
                for word in words:
                    if match(element[-1], word) == True and word not in element:
                        tmp = copy.deepcopy(element)
                        tmp.append(word)
                        q.append(tmp)
        answer = len(min(posibility, key=lambda x: len(x)))-1
    return answer


if __name__ == "__main__":
    print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
    print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))
