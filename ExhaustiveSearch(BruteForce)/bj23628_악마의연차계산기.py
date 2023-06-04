import sys

s = list(map(int,sys.stdin.readline().rstrip().split()))
e = list(map(int,sys.stdin.readline().rstrip().split()))

year = e[0] - s[0]
month = e[1] - s[1]
day = e[2] - s[2]

# print(year,month,day)
# 1. 근무기간 계산 days
days = day + month*30 + year*30*12

# 2. 월차 계산
if year >3:
    wolcha = 36
else:
    if month<0:
        wolcha = year*12 + month
    else:
        wolcha = year*12
    if day < 0:
        wolcha-=1


# 3. 연차 계산
A,ncha=0,0
for i in range(year):
    if i!=0 and i%2 == 0:
        A+=1
    ncha += A+15
if month < 0:
    ncha -= A+15
elif month == 0:
    if day < 0:
        ncha -= A+15

print(ncha,wolcha)
print(days,"days",sep="")


