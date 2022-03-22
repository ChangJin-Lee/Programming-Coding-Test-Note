m = int(input())
n = int(input())

sqnum=[]
for i in range(m,n+1):
    if (int(i**0.5))**2 == i:
        sqnum.append(i)

if not sqnum:
    print(-1)
else:
    print(f'{sum(sqnum)}\n{sqnum[0]}')