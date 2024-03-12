#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n, px, py;
vector<string> map;
vector<vector<bool>> visited;
vector<int> countDanji;

bool checkMap();
void bfs(int x, int y);

int main()
{
    fastcpp;
    cin >> n;

    map.assign(n,"");
    visited.assign(n,vector<bool>(n,false));

    for(int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    while(checkMap())
    {
        bfs(px,py);
    }
    

    sort(countDanji.begin(),countDanji.end());

    cout << countDanji.size() << "\n";
    for(auto k : countDanji)
    {
        cout << k << "\n";
    }
}

bool checkMap()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && map[i][j] == '1')
            {
                px = i;
                py = j;
                return true;
            }
        }
    }

    return false;
}

void bfs(int x, int y)
{
    int movable[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    queue<pair<int,int>> q;
    int countApart = 0;

    if(map[x][y] == '1')
        countApart++;

    visited[x][y] = true;
    q.push({x,y});


    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(auto nextPosition : movable)
        {
            int nx = nextPosition[0] + cx;
            int ny = nextPosition[1] + cy;

            if(0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if(!visited[nx][ny])
                {
                    if(map[nx][ny] == '1')
                    {
                        q.push({nx,ny});
                        countApart++;
                    }
                    visited[nx][ny] = true;
                }
            }
        }
    }
    countDanji.push_back(countApart);
}