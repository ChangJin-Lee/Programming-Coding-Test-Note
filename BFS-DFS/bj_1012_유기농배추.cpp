#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int m, n;
vector<vector<int>> map;
vector<vector<bool>> visited;
pair<int,int> movable[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void bfs(int sx, int sy);

int main()
{
    fastcpp;
    int t, k, x, y;

    cin >> t ;

    while(t--)
    {
        int answer = 0;
        vector<pair<int,int>> startingPoints;
        cin >> m >> n >> k;
        map.assign(m,vector<int>(n,0));
        visited.assign(m,vector<bool>(n,false));
        
        while(k--)
        {
            cin >> x >> y;
            map[x][y] = 1;
            startingPoints.push_back({x,y});
        }

        for(auto startingPoint : startingPoints)
        {
            int px = startingPoint.first;
            int py = startingPoint.second;
            if(!visited[px][py])
            {
                bfs(px, py);
                answer++;
            }
        }

        map.clear();
        visited.clear();
        cout << answer << "\n";
    }
}

void bfs(int sx, int sy)
{
    queue<pair<int,int>> q;

    visited[sx][sy] = true;
    q.push({sx,sy});

    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(auto next : movable)
        {
            int nx = cx + next.first;
            int ny = cy + next.second;

            if(0 <= nx && nx < m && 0 <= ny && ny < n)
            {
                if(!visited[nx][ny] && map[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
}