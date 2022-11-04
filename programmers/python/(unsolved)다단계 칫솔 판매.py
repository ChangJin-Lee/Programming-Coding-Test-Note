from collections import defaultdict


def solution(enroll, referral, seller, amount):
    tinfo = {}
    total = defaultdict(int)
    for parent, child in zip(enroll, referral):
        tinfo[parent] = child
        total[parent] = 0
    for sales, price in zip(seller, amount):
        price = price*100
        p = sales
        l = tinfo[sales]
        # if l =="-":
        #     total[sales] += price
        # else:
        #     p = sales
        while l != "-":
            print(price)
            tprice = int(price * 0.9)
            price -= tprice
            print(p, l, tprice, price)
            total[p] += tprice
            p = l
            l = tinfo[l]

        if price < 10:
            total[p] += price
        else:
            tprice = round(price * 0.9)
            price -= tprice
            total[p] += tprice
        print(p, l, tprice, price)
    answer = list(total.values())
    return answer

# [360,958,108,0,450,18,180,1080]


print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"], ["-", "-", "mary", "edward", "mary", "mary",
      "jaimie", "edward"],	["young", "john", "tod", "emily", "mary"],	[12, 4, 2, 5, 10]))
print([360, 958, 108, 0, 450, 18, 180, 1080])
