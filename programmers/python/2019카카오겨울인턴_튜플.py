def solution(s):
    answer = []
    stacks = []
    stack = []
    slist = list(s)
    while slist:
        spops = slist.pop(0)
        target = ""
        if spops == "}":
            if stack != []:
                stacks.append(stack)
                stack = []
        elif spops != "{" and spops != ",":
            target += spops
            while slist:
                spops = slist.pop(0)
                if spops != "}" and spops != ",":
                    target += spops
                else:
                    break
            stack.append(int(target))
            if spops == "}":
                if stack != []:
                    stacks.append(stack)
                    stack = []
    maxlen = 0
    for stack in stacks:
        if maxlen < len(stack):
            maxlen = len(stack)
    for i in range(1,maxlen+1):
        for stack in stacks:
            if len(stack) == i:
                for k in stack:
                    if k not in answer:
                        answer.append(k)
    return answer

solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")   # [2, 1, 3, 4]
solution("{{1,2,3},{2,1},{1,2,4,3},{2}}")   # [2, 1, 3, 4]
solution("{{20,111},{111}}")                # [111, 20]
solution("{{123}}")                         # [123]
solution("{{4,2,3},{3},{2,3,4,1},{2,3}}")   # [3, 2, 4, 1]