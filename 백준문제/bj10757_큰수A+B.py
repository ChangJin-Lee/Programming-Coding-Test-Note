# 주어진 정수를 str로 입력받아서 한자리 수의 더하기를 여러번 하는 문제로 바꿔서 푼다.
import sys
A,B = sys.stdin.readline().rstrip().split()
A,B = list(map(int,reversed(A))), list(map(int,reversed(B)))
lenA,lenB = len(A),len(B)
if lenA > lenB: 
    index = lenA
    for i in range(lenA-lenB): B.append(0)
else: 
    index = lenB
    for i in range(lenB-lenA): A.append(0)
checktens = False
C=[]
for i in range(index):
    addnum = A[i] + B[i]
    if checktens: addnum+=1
    if addnum > 9 :  checktens = True; C.append(addnum%10)
    else: checktens = False; C.append(addnum)
if checktens: C.append(1)
print("".join(list(map(str,reversed(C)))))