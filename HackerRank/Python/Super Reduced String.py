# aaabccddd
# ppffccmmssnnhhbbmmggxxaaooeeqqeennffzzaaeeyyaaggggeessvvssggbbccnnrrjjxxuuzzbbjjrruuaaccaaoommkkkkxx
def superReducedString(s):
    s = list(s)
    i=0
    result = ""
    temp = 0
    while True:
        if i >= len(s)-1:
            break
        if s[i] == s[i+1]:
            s.pop(i)
            s.pop(i)
            i=0
        else:
            i+=1
    if not s:
        result = "Empty String"
    else:
        result = "".join(s)
    return result
    # Write your code here

s = input()
result = superReducedString(s)
print(result)