import sys

input = list(map(str, sys.stdin.readline()))
D2 = False
for i in range(len(input) - 1):
    if input[i] + input[i + 1] == "d2" or input[i] + input[i + 1] == "D2":
        D2 = True
if D2 == True:
    print("D2")
else:
    print("unrated")