import sys
def hannumber(a,t): # a는 리스트, t는 인덱스
    for i in range(100,t):
        temp = list(map(int,list(str(i))))
        if temp[2]-temp[1] != temp[1]-temp[0]: a[i] = "x"
    return sn.count("o")-1

N = int(sys.stdin.readline())
if(N<100): print(N)
else:
    sn = ["o" for k in range(N+1)]
    print(hannumber(sn,N+1))
