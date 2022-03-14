import sys
def switchplayer(player):
    # 현재 플레이어가 누구인가?
    if player == "R":
        player = "B"
    else:
        player = "R"
    return player
t = int(sys.stdin.readline().rstrip())

player = "R"
for _ in range(t):
    x,y,z = map(int,sys.stdin.readline().rstrip().split())
    if x == 1 and y == 1 and z == 1:
        player = switchplayer(player)
        print(player)
    elif x ==1 and y == 1 and z != 1:

    elif x == 1 and y!=1 and z != 1:

    elif x == 1 and y!=1 and z ==1:

    elif x !=1 and y==1 and z!=1:

    elif x != 1 and y == 1 and z==1:

    elif x !=1 and y !=1 and z ==1:



