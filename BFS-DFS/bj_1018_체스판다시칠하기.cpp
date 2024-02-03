#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

vector<string> v;

int bfs(int x, int y, bool change);

int main()
{
    fastcpp;
    int n,m;
    string input;
    int answer = 2500;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0; i < n-7; i++)
    {
        for(int j = 0; j < m-7; j++)
        {
            int tmp = bfs(i, j, true);
            int tmp2 = bfs(i, j, false);

            answer = min({tmp,tmp2,answer});
        }
    }

    cout << answer;
}

int bfs(int x, int y, bool change)
{
    vector<pair<int,int>> moving = {{1,0}, {0,-1}, {-1,0}, {0,1}};
    vector<vector<char>> map;
    vector<vector<bool>> visit;
    queue<pair<int,int>> q;
    int value = 0;

    for(int i = x; i < x + 8; i++)
    {
        vector<bool> tmp;
        vector<char> tmp2;
        for(int j = y; j < y + 8; j++)
        {
            tmp.push_back(false);
            tmp2.push_back(v[i][j]);
        }
        visit.push_back(tmp);
        map.push_back(tmp2);
    }

    if(change)
    {
        value++;
        if(map[0][0] == 'W')
            map[0][0] = 'B';
        else
            map[0][0] = 'W';
    }

    q.push({0,0});
    visit[0][0]=true;

    while(!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();

        int ax = front.first;
        int ay = front.second;

        for(auto k : moving)
        {
            int tx = ax + k.first;
            int ty = ay + k.second;

            if(0 <= tx && tx < 8 && 0 <= ty && ty < 8)
            {
                if(!visit[tx][ty])
                {
                    if(map[ax][ay] == map[tx][ty])
                    {
                        if(map[ax][ay] == 'W')
                            map[tx][ty] = 'B';
                        else
                            map[tx][ty] = 'W';
                        value++;
                    }
                    q.push({tx,ty});
                    visit[tx][ty] = true;
                }
            }
        }
    }

    return value;
}