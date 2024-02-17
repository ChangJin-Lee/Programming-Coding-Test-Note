# list.sort(key = lambda x : len(x))
# 를 사용하는 문제였다. 배열의 크기순으로 배열을 정렬하는 방법에 대해서 알아두어야한다.
# 파이썬스러운 코드를 처음에 생각했는데, 배열의 크기순으로 정렬하는 것에 대해서 생각하지 못했다.
# 돌고돌아 정답은 맞췄지만, 시간초과가 많이 나왔다. 다른 사람의 풀이를 보고 sort() 함수의 key를 사용하
# 방법에 대해서 알게 되었다. 문제를 쉽게 봐야하는것 같다. 너무 어렵게 돌아갈만한 문제들은 애초부터 예시를 많이 준다.

# def solution(s):
#     answer = []
#     stacks = []
#     stack = []
#     slist = list(s)
#     while slist:
#         spops = slist.pop(0)
#         target = ""
#         if spops == "}":
#             if stack != []:
#                 stacks.append(stack)
#                 stack = []
#         elif spops != "{" and spops != ",":
#             target += spops
#             while slist:
#                 spops = slist.pop(0)
#                 if spops != "}" and spops != ",":
#                     target += spops
#                 else:
#                     break
#             stack.append(int(target))
#             if spops == "}":
#                 if stack != []:
#                     stacks.append(stack)
#                     stack = []
#     maxlen = 0
#     for stack in stacks:
#         if maxlen < len(stack):
#             maxlen = len(stack)
#     for i in range(1,maxlen+1):
#         for stack in stacks:
#             if len(stack) == i:
#                 for k in stack:
#                     if k not in answer:
#                         answer.append(k)
#     return answer

def solution(s):
    answer = []
    words = s[2:-2].split('},{')
    for i in range(len(words)):
        words[i] = list(map(int,words[i].split(",")))
    words.sort(key = lambda x : len(x))
    for word in words:
        for w in word:
            if w not in answer:
                answer.append(w)
    return answer

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))   # [2, 1, 3, 4]
print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))   # [2, 1, 3, 4]
print(solution("{{20,111},{111}}"))                # [111, 20]
print(solution("{{123}}"))                         # [123]
print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))   # [3, 2, 4, 1]