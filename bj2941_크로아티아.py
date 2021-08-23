# import sys
# croatia = ["c=","c-","dz=","d-","lj","nj","s=","z="]
# def ispossible(word):
#     for i in range(len(croatia)):
#         if word in croatia[i]: return True
#     return False
# def croatiaword(word,wordset):
#     for i in range(len(croatia)):
#         if croatia[i] in word:
#             # print(word, croatia[i])
#             word = word.replace(croatia[i],"")
#             for k in range(len(word)): wordset.append(word[k]); word = word.replace(word[k],"")
#             # print(word, croatia[i])
#             wordset.append(croatia[i])
#     return word
# def solution(sentence):
#     # print(sentence)
#     temp=""
#     wordset=[]
#     for i in range(len(sentence)):
#         pops = sentence.pop(0)
#         # print(sentence,temp,pops,list(wordset))
#         if ispossible(pops):
#             temp += pops
#             temp = croatiaword(temp,wordset)
#             # print("temp : " + temp)
#         else: wordset.append(pops)
#     if temp != "" : wordset.append(temp)
#     return wordset
# alpha = list(map(str,sys.stdin.readline().rstrip()))
# print(len(solution(alpha)))

# 너무 어렵게 생각했음...
import sys
croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
s = sys.stdin.readline().rstrip()
for i in croatia:
    s = s.replace(i,'_')
    print(s)
print(len(s))
print("test")