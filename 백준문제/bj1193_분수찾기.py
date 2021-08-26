#bj1193_분수찾기
#2차방정식 실근 찾는 함수 이용
import sys
def roots(a,b,c):
    D = (b*b - 4*a*c)**0.5        
    x_1 = (-b + D) / (2*a)
    x_2 = (-b - D) / (2*a)
    return int(x_1)

an, n = [], 1
while (n * (n - 1) / 2) +1 < 10000000:
	an.append(int(n * (n - 1) / 2)+1)
	n+=1
# print(an[3],an[4])
x = int(sys.stdin.readline())
index = roots(1,-1,-2*(x-1))
startpoint = an[index-1]
# print(index,startpoint)
if index%2==0: A,B=1+x-startpoint,index-x+startpoint
else: A,B=index-x+startpoint,1+x-startpoint
print("{}/{}".format(A,B))

# 숏코딩
# X=int(sys.stdin.readline())
# n=k=0
# while X>n:n+=k;k+=1
# a=k-n+X-1
# if k%2:a=k-a
# print(f'{k-a}/{a}')

# 수정 해 불고
# 똥싸고
# 되나?
# 오 된다. 풀 푸시 해얃괴네
# 풀 푸시 안해도 자동으로 됨