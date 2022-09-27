from collections import defaultdict
def solution(clothes):
    dic = defaultdict(list)
    res = 1
    for item, key in clothes:
        dic[key].append(item)

    for key in dic.keys():
        res *= len(dic[key]) + 1

    res -= 1
    return res

if __name__ == "__main__":
    # 5 3
    print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
    print(solution([["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]))