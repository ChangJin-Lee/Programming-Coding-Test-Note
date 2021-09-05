import sys

def T_H(A,B,C,n,list):
    if(n<=0): return 0
    T_H(A,C,B,n-1,list)
    list.append(str(A)+" "+str(C))
    T_H(B,A,C,n-1,list)

k=[]
T_H(1,2,3,int(sys.stdin.readline().rstrip()),k)
print(len(k))
for m in k: print(m)