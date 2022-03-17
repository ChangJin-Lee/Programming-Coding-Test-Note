import sys

while True:
    input = list(map(int,sys.stdin.readline().rstrip().split()))
    if input[0]==input[1]==input[2]==0: break
    maxside = input.pop(input.index(max(input)))
    if maxside**2 == input[0]**2 + input[1]**2: print("right")
    else: print("wrong")