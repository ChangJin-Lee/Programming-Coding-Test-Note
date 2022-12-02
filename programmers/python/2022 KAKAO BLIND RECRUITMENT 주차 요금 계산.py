from collections import defaultdict
import math

def solution(fees, records):
    answer = []
    cars = defaultdict(list)
    mcars = defaultdict(int)
    for record in records:
        r = list(record.split())
        if r[2] == "IN":
            cars[r[1]]=r[0]
        else:
            b = list(map(int,cars[r[1]].split(":")))
            a = list(map(int,r[0].split(":")))
            h = a[0]-b[0]
            m = a[1]-b[1]
            mcars[r[1]] += h*60 + m
            cars[r[1]] = 0
    for ck,cv in cars.items():
        if cv != 0:
            b = list(map(int,cv.split(":")))
            mcars[ck] += (23 - b[0]) * 60 + 59 - b[1]
    mcars = sorted(mcars.items(), key=lambda x : x[0])
    # print(mcars[0][1])
    for i, (mk, mv) in enumerate(mcars):
        # print(i,mk,mv)
        price = 0
        if mv <= fees[0]:
            price = fees[1]
        else:
            a = math.ceil((mv - fees[0])/fees[2])*fees[3]
            price = fees[1] + a
        answer.append(price)
    # print(mcars)
    return answer

print(solution([180, 5000, 10, 600],["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
# [14600, 34400, 5000]
print(solution([120, 0, 60, 591],["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"]))
# [0, 591]
print(solution([1, 461, 1, 10],	["00:00 1234 IN"]))
# [14841]

# print(solution())

