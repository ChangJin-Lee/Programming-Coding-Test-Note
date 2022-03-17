import sys, math
input = list(map(int,sys.stdin.readline().split()))
if input[1]>=input[2] :
    print("-1")
else:
    if input[0] == 0: print(input[2] - input[1])
    else:
        point = input[0]/(input[2]-input[1])
        if point - int(point) >0:print(math.ceil(point))
        else: print(int(point)+1)