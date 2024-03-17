#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n, px, py;
vector<vector<int>> map;
vector<vector<bool>> visit;
set<int> rainsHeights;
pair<int,int> movable[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool FindVisit();
void ClearVisit();
void SetMap(int h);
void bfs(int x, int y);

int main()
{
    fastcpp;
    string input;
    int answer = 0;

    cin >> n;
    
    px = -1;
    py = -1;
    map.assign(n, vector<int>(n));
    visit.assign(n, vector<bool>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            rainsHeights.insert(map[i][j]);
        }
    }
    

    for(auto rainsHeight : rainsHeights)
    {
        int t = 0;
        SetMap(rainsHeight);
        while(FindVisit())
        {
            bfs(px,py);
            t++;
        }
        answer = max(answer, t);
        ClearVisit();
    }
    
    if(answer != 0)
        cout << answer;
    else
        cout << 1;
}

bool FindVisit()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visit[i][j])
            {
                px = i;
                py = j;
                return true;
            }
        }
    }
    px = -1;
    py = -1;
    return false;
}

void ClearVisit()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }
}

void SetMap(int h)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] <= h)
            {
                visit[i][j] = true;
            }
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int,int>> q;

    visit[x][y] = true;
    q.push({x,y});
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(auto dAxis : movable)
        {
            int nx = cx + dAxis.first;
            int ny = cy + dAxis.second;

            if(0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if(!visit[nx][ny])
                {
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }

    }

}