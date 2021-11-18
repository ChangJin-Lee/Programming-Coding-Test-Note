def isValid(s):
    dic = {}
    cnts = []
    result = ""
    st = 0
    if len(s) == 1:
        result = "YES"
    else:
        for word in s:
            if word not in dic:
                dic[word] = 1
            else:
                dic[word]+=1
        for cnt in dic:
            cnts.append(dic[cnt])
        othercnt = 0
        # 12111111
        # 11211111
        # 21111111
        if cnts.count(cnts[0]) == 1:
            if cnts.counts(cnts[1]) == len(cnts)-1:
                if cnts[0] - 1 == cnts[1]:
                    result = "YES"
        elif cnts.count(cnts[0]) == len(cnts)-1:
            for i in range(len(cnts)-1):
                if cnts[i] == cnts[i+1] - 1:
                    result = "YES"
                    break
                elif cnts[i] - 1 == cnts[i+1]:
                    if cnts[i+1] == 1:
                        result = "YES"
                        break
                    else:
                        result = "NO"
        else:
            result = "NO"
    return result
    # Write your code here