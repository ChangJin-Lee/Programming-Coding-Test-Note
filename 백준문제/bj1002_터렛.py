import sys
T = int(sys.stdin.readline().rstrip())
for _ in range(T):
    x1,y1,r1,x2,y2,r2 = map(int,sys.stdin.readline().rstrip().split())
    d = (x1-x2)**2 + (y1-y2)**2
    incircle = (r1-r2)**2
    outcircle = (r1+r2)**2
    if r1>r2: maxr = r1**2
    else: maxr = r2**2
    print(d,maxr, incircle, outcircle)
    print(type(d), type(maxr), type(incircle), type(outcircle))
    print(d**0.5,r1+r2)



    # if x1==x2==y1==y2 and r1==r2: print(-1)
    # elif d == outcircle: print(1)
    # elif d == incircle : print(1)
    # elif d > outcircle : print(0)
    # elif d <= maxr and d<incircle: print(0)
    # else: print(2)




    # if x1==x2==y1==y2:
    #     if r1==r2:print(-1)
    #     else:print(0)
    # else:
    #     if d < maxr:
    #         print("위")
    #         if d < incircle : print(0)
    #         elif d == incircle: print(1)
    #         else:print(2)
    #     elif d==max: print(2)
    #     else:
    #         print("아래")
    #         if outcircle > d: print(2)
    #         elif outcircle == d: print(1)
    #         else: print(0)
    #
    #         n = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    r = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (1 / 2)
    R = [r1, r2, r]
    m = max(R); R.remove(m)
    print(-1 if (r == 0 and r1 == r2) else 1 if (r == r1 + r2 or m == sum(R)) else 0 if (m > sum(R)) else 2)