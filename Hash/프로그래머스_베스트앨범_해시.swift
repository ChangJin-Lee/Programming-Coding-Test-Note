// 파이썬으로 풀었던 문제 스위프트로 다시 풀어보기
// dictionary in dictionary 를 구현해보려고 했는데 그지같은 optional과 init 처리때문에 
// dictionary 두 개를 사용해서 풀었습니다.
// 해당 장르의 순위를 알기 위한 rateAlbum
// 해당 장르 내에 속한 음악(고유번호로 지정)을 알기 위한 bestAlbum
// 둘을 sorting 시키고 
// 트릭을 알려 주자면 bestAlbum에 저장할때 장르 이름과 고유 번호를 같이 저장함.
// ex) bestAlbum["classic 23"] = 500
// 그러면 나중에 bestAlbum의 key값을 가져와서 해당하는 고유번호와 장르를 분리할 수 있음.
// 이것을 이용해서 해시처럼 사용하면 됩니다. 
// 이거 원래 파이썬에서 구현하면 시간초과나는데 스위프트에선 빠르게 잘 됩니다. 굿.

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {

    var bestAlbum: [String: Int] = [:]
    var rateAlbum: [String: Int] = [:]
    var answer: [Int] = []

    for i in 0..<genres.count{
        if rateAlbum[genres[i]] != nil{
            rateAlbum[genres[i]]!+=plays[i]
        }
        else{
            rateAlbum[genres[i]] = plays[i]
        }
        bestAlbum[genres[i] + " " + String(i)] = plays[i]
    }

    let sortedRateAlbum = rateAlbum.sorted{ $0.1 > $1.1}
    let sortedBestAlbum = bestAlbum.sorted{ $0.1 > $1.1}

    for (rKey, _) in sortedRateAlbum{
        var temp: [Int] = []
        var chk: Bool = false
        for (bKey, _) in sortedBestAlbum{
            if bKey.contains(rKey) {
                let lastIndx = bKey.split(separator: " ")[1]
                temp.append(Int(lastIndx)!)
                if temp.count == 2 {
                    for t in temp{
                        answer.append(t)
                    }
                    chk = true
                    break
                }
            }
        }
        if (chk != true && temp.count < 2){
            chk = false
            for t in temp{
                answer.append(t)
            }
        }
    }


    return answer
}

print(solution(["classic", "pop", "classic", "classic", "pop", "dance", "trtr"],
               [500, 600, 150, 800, 2500, 500, 500]))
