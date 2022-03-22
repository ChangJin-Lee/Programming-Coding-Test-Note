def selfnumber(a,t): # a는 리스트, t는 생성자
    while True:
        temp = list(map(int,list(str(t))))
        t = t + sum(temp)
        if t > 10000: return
        a[t] = "x"

sn = ["o" for k in range(10001)]
for i in range(1,10001):
    if sn[i]=="o": selfnumber(sn,i); print(i)
