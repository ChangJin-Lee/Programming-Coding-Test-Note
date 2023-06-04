// 프로그래머스 lv2 연속 부분 수열 합의 개수
// 풀이시간. 19:52

import Foundation

func solution(_ elements:[Int]) -> Int {
    var copy_elements = elements
    var set_elements: Set<Int> = []
    
    for element in elements{
        copy_elements.append(element)
    }

    for i in 0..<elements.count{
        for j in 0..<elements.count{
            var sumval = 0
            for k in j..<j+i+1{
                sumval += copy_elements[k]
            }
            set_elements.insert(sumval)
        }
    }
    
    return set_elements.count
}

print(solution([7,9,1,1,4]))