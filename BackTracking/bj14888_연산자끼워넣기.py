import sys, itertools
exp = ["+","-","*","/"]
n = int(sys.stdin.readline().rstrip())
A = list(map(int,sys.stdin.readline().rstrip().split()))
calculations = list(map(int,sys.stdin.readline().rstrip().split()))
combi, index = [],0
for calculation in calculations:
    for i in range(calculation):
        combi.append(exp[index])
    index+=1

# print(combi)

my_calculations = list(itertools.permutations(combi,len(combi)))

com_calculations = list(set(my_calculations))

# print(com_calculations)

result=[]
for com_calculation in com_calculations:
    expression = str(A[0])+com_calculation[0]+str(A[1])
    temp = int(eval(expression))
    for i in range(2,n):
        expression = ""
        expression = str(temp)+ com_calculation[i-1] + str(A[i])
        temp = int(eval(expression))
    result.append(temp)
    # if temp == 48:
    #     print(com_calculation)

# print(result)

print(max(result),min(result), sep="\n")