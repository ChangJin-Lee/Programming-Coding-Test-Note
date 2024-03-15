#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<pair<bool,bool>>> visit;
pair<int,int> movable[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int bfs();

int main()
{
    fastcpp;
    string input;
    vector<pair<int,int>> startingPoints;
    int answer = -1;

    cin >> n >> m;

    map.assign(n, vector<int>(m));
    visit.assign(n, vector<pair<bool,bool>>(m));

    for(int i = 0; i < n; i++)
    {
        cin >> input;

        for(int j = 0; j < m; j++)
        {
            map[i][j] = int(input[j]) - int('0');
        }
    }

    answer = bfs();

    if(answer != 1000001)
        cout << answer;
    else
        cout << -1;
}

int bfs()
{
    queue<tuple<int,int,int,bool>> q;
    int answer = 1000001;

    visit[0][0].first = true;
    visit[0][0].second = true;
    q.push({0,0,1,false});
    
    while(!q.empty())
    {
        tuple<int,int,int,bool> front = q.front();
        q.pop();

        if(get<0>(front) == n-1 && get<1>(front) == m-1)
        {
            answer = min(answer,get<2>(front));
        }
        
        for(auto dAxis : movable)
        {
            int nx = get<0>(front) + dAxis.first;
            int ny = get<1>(front) + dAxis.second;
            int level = get<2>(front);
            int isBreak = get<3>(front);

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(!isBreak)
                {
                    if(!visit[nx][ny].first)
                    {
                        visit[nx][ny].first = true;

                        if(map[nx][ny] == 1)
                        {
                            if(!isBreak)
                            {
                                q.push({nx,ny,level+1,true});
                            }
                        }
                        else if(map[nx][ny] == 0)
                        {
                            q.push({nx,ny,level+1,isBreak});
                        }
                    }
                }
                else
                {
                    if(!visit[nx][ny].second)
                    {
                        visit[nx][ny].second = true;
                        if(map[nx][ny] == 0)
                        {
                            q.push({nx,ny,level+1,isBreak});
                        }
                    }
                }
            }
        }

    }

    return answer;
}