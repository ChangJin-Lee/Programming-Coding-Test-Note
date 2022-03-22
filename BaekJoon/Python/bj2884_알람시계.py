# 원래풀이
H,M = map(int,input().split())
if M>=45:
    M=M-45
else:
    M=45-M
    M=60-M
    if H==0:
        H=23
    else:
        H=H-1
print(H,M,end="")

## 숏코딩
# a,b=map(int,input().split())
# print((a-(b<45))%24,(b-45)%60)