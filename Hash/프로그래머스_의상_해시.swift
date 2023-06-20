import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var clothtypes: [String: [String]] = [:]
    var multipleType = 1
    for cloth in clothes{
        if clothtypes[cloth[1]] == nil{
            clothtypes[cloth[1]] = [cloth[0]]
        }
        else{
            clothtypes[cloth[1]]!.append(cloth[0])
        }
    }

    for clothtype in clothtypes.values{
        multipleType *= (clothtype.count + 1)
    }

    return multipleType - 1
}

print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
