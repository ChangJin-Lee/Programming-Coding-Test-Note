def solution(board, skill):
    
    def checkAttackOrDefence(command: int) -> str:
        if command == 1: 
            return "attacked"
        elif command == 2:
            return "cure"
    
    def calculateXYAxis(spell: list, isAttack: bool) -> list:
        for xaxis in range(spell[1],spell[3]+1):
                for yaxis in range(spell[2],spell[4]+1):
                    if isAttack == True:
                        board[xaxis][yaxis] -= spell[5]
                    else:
                        board[xaxis][yaxis] += spell[5]
        return board
    
    def calculateBuildingCount():
        cnt = 0
        for xBoard in board:
            for durability in xBoard:
                if durability > 0:
                    cnt += 1
        return cnt
    
    for spell in skill:
        if checkAttackOrDefence(spell[0]) == "attacked":
            board = calculateXYAxis(spell=spell, isAttack=True)
        elif checkAttackOrDefence(spell[0]) == "cure":
            board = calculateXYAxis(spell=spell, isAttack=False)
    
    buildingCount = calculateBuildingCount()
    
    return buildingCount


print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))
print(solution([[1,2,3],[4,5,6],[7,8,9]], 	[[1,1,1,2,2,4],[1,0,0,1,1,2],[2,2,0,2,0,100]]))