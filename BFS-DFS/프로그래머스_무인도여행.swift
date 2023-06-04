// 풀이시간.  58:59

// 개빡치게 X를 x로 착각하고 있었음
// 그러니 nil로 나오지

import Foundation

func solution(_ maps:[String]) -> [Int] {
    let rows = maps.count
    let cols = maps[0].count
    var Visit: [[Bool]] = [[Bool]](repeating: [Bool](repeating: false, count: cols), count: rows)
    var mapsinfo: [[Character]] = []
    
    for str in maps{
        let chr = Array(str)
        mapsinfo.append(chr)
    }

    func bfs(x: Int, y: Int) -> Int{
        Visit[x][y] = true
        var q: [(Int,Int)] = [(x,y)]
        var result = 0
        
        while !q.isEmpty {
            let (x,y) = q.removeFirst()
            if let b =  mapsinfo[x][y].wholeNumberValue{
                result += b
            }
            
            for (dx,dy) in [(-1,0),(1,0),(0,-1),(0,1)]{
                let (nx,ny) = (dx + x, dy + y)
                
                if ( ((0 <= nx) && (nx < rows)) && ((0 <= ny) && ny < cols)){
                    if(mapsinfo[nx][ny] != "X" && Visit[nx][ny] == false){
                        Visit[nx][ny] = true
                        q.append((nx,ny))
                    }
                }
            }
            
        }
        
        return result
    }

    var results: [Int] = []
    for i in 0..<rows{
        for j in 0..<cols{
            if (Visit[i][j] == false && mapsinfo[i][j] != "X"){
                results.append(bfs(x: i, y: j))
            }
        }
    }
    if results.isEmpty{
        return [-1]
    }
    else{
        return results.sorted()
    }
}
print(solution(["X591X","X1X5X","X231X", "1XXX1"]))




// func solution(_ maps:[String]) -> [Int] {
//     let rows = maps.count
//     let cols = maps[0].count
//     var Visit = [[Bool]](repeating: [Bool](repeating: false, count: cols), count: rows)

//     func bfs(x: Int, y: Int) -> Int{
//         Visit[x][y] = true
//         var q: [[Int]] = [[x,y]]
//         var result = 0

//         while !q.isEmpty{
//             let pos = q.removeFirst()
//             let dx: Int = pos[0]
//             let dy: Int = pos[1]

//             result += Int(String(Array(maps[dx])[dy]))

//             for move in [[1,0],[0,1],[-1,0],[0,1]]{
//                let nx = dx + move[0]
//                let ny = dy + move[1]

//                if (0 <= nx && nx < rows && 0 <= ny && ny < cols){
//                 if (Visit[nx][ny] == false && Array(maps[nx])[ny] != "x"){
//                     Visit[nx][ny] = true
//                     q.append([nx,ny])
//                     }
//                }
//             }
//         }
//         return result
//     }


//     for i in 0..<rows{
//         for j in 0..<cols{
//             if (Visit[i][j] == false || Array(maps[i])[j] != "x"){
//                 print(bfs(x: i,y: j))
//             }
//         }
//     }

//     return []
// }

// print(solution(["X591X","X1X5X","X231X", "1XXX1"]))