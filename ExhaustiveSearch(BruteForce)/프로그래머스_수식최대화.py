import itertools
import copy
expset = ["+","-","*"]
def solution(expression):
    answer = 0
    expression = list(expression)
    priority = list(itertools.permutations(expset,3))
    exp = []
    # split expressions and numbers
    for i in range(len(expression)):
        if expression[i] in expset:
            exp.append(expression[i])
            expression[i] = " "
    numbers = list(map(int,"".join(expression).split(" ")))
    for ex in priority:
        cnumbers = copy.deepcopy(numbers)
        cexp = copy.deepcopy(exp)
        for i in range(3):
            j=0
            while True:
                if j >= len(cexp):
                    break
                if cexp[j] == ex[i]:
                    if cexp[j] == "-":
                        cnumbers[j] -= cnumbers[j+1]
                    elif cexp[j] == "+":
                        cnumbers[j] += cnumbers[j+1]
                    elif cexp[j] == "*":
                        cnumbers[j] *= cnumbers[j+1]
                    cnumbers.pop(j+1)
                    cexp.pop(j)
                else:
                    j+=1
        if abs(cnumbers[0]) > answer:
            answer = abs(cnumbers[0])
    return answer

print(solution("100-200*300-500+20")) ## 60420
print(solution("50*6-3*2")) ## 300