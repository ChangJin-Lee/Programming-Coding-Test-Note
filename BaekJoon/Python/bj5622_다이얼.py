import sys
dial = ['ABC','DEF','GHI','JKL','MNO','PQRS','TUV','WXYZ']
input = sys.stdin.readline().rstrip()
num = []
for i in range(len(input)):
    for j in range(8):
        if input[i] in dial[j]:
            num.append(j+3)
print(sum(num))