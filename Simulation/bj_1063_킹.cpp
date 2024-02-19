#include <iostream>
#include <vector>
#include <map>

#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

map<string,pair<int,int>> movable;

int main()
{
    fastcpp;
    int n;
    string input1, input2;
    vector<vector<int>> map(51, vector<int>(51,0));
    pair<int,int> playerPosition;
    pair<int,int> stonePosition;
    
    cin >> input1 >> input2 >> n;

    movable["R"] = {1,0};
    movable["L"] = {-1,0};
    movable["B"] = {0,-1};
    movable["T"] = {0,1};
    movable["RT"] = {1,1};
    movable["LT"] = {-1,1};
    movable["RB"] = {1,-1};
    movable["LB"] = {-1,-1};

    playerPosition.first = int(input1[0]) - int('A') + 1;
    playerPosition.second = int(input1[1]) - int('0');

    stonePosition.first = int(input2[0]) - int('A') + 1;
    stonePosition.second = int(input2[1]) - int('0');

    for(int i = 0; i < n; i++)
    {
        cin >> input1;

        int nextPlayerX = playerPosition.first + movable[input1].first;
        int nextPlayerY = playerPosition.second + movable[input1].second;

        if(nextPlayerX == stonePosition.first && nextPlayerY == stonePosition.second)
        {
            int nextStoneX = stonePosition.first + movable[input1].first;
            int nextStoneY = stonePosition.second + movable[input1].second;

            if(nextPlayerX == stonePosition.first && nextPlayerY == stonePosition.second)
            {
                if(((1 <= nextStoneX && nextStoneX <= 8 ) && (1 <= nextStoneY && nextStoneY <= 8)))
                {
                    playerPosition.first += movable[input1].first;
                    playerPosition.second += movable[input1].second;
                    stonePosition.first += movable[input1].first;
                    stonePosition.second += movable[input1].second;
                }
            }
            else
            {
                playerPosition.first += movable[input1].first;
                playerPosition.second += movable[input1].second;
            }
        }
        else
        {
            if(((1 <= nextPlayerX && nextPlayerX <= 8 ) && (1 <= nextPlayerY && nextPlayerY <= 8)))
                {
                    playerPosition.first += movable[input1].first;
                    playerPosition.second += movable[input1].second;
                }
        }
    }

    cout << char(int(playerPosition.first) + int('A') - 1) << playerPosition.second << "\n";
    cout << char(int(stonePosition.first) + int('A') - 1) << stonePosition.second << "\n";
}