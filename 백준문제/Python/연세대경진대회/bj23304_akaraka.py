import sys
sys.setrecursionlimit(10**4)
def ispalindrome(strings):
    #print(strings)
    if len(strings) == 1:
        return True
    elif len(strings) == 2:
        if strings[0] != strings[1]:
            return False
        else:
            return True
    else:
        str_recursive = strings[::-1]
        prefix = strings[:int(len(strings)/2)]
        postfix = strings[int(len(strings)/2)+1:]
        #print(str_recursive,prefix,postfix)
        #if str_recursive == strings and ispalindrome(prefix) and ispalindrome(postfix):
        if ispalindrome(prefix) and ispalindrome(postfix) and str_recursive == strings:
            return True
        else:
            return False

strings = str(sys.stdin.readline().rstrip())
if(ispalindrome(strings)): print("AKARAKA")
else: print("IPSELENTI")