#include <iostream>
#include <queue>
#include <vector> 
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
vector<pair<int,int>> moving = {{0,1}, {1,0}, {0,-1}, {-1,0}};
vector<pair<int, int>> start;

vector<vector<int>> preBFS(int k, int n);
int bfs(vector<vector<int>> v, vector<vector<bool>> visit);

int main()
{
    fastcpp;
    int front, input;
    int foo;
    int answer = 0;
    vector<int> tmp;
    vector<bool> tmpB;
    vector<vector<int>> v;
    vector<vector<bool>> visit;
    vector<pair<int,int>> zeroLocations;
    queue<int> q;

    vector<vector<int>> dd;
    
    cin >> n >> m;

    for(int row = 0; row < n; row++)
    {
        tmp.clear();
        tmpB.clear();
        for(int col = 0; col < m; col++)
        {
            cin >> input;
            if(input == 2)
            {
                start.push_back({row,col});
            }
            else if ( input == 0)
            {
                zeroLocations.push_back({row, col});
            }
            tmp.push_back(input);
            tmpB.push_back(false);
        }
        v.push_back(tmp);
        visit.push_back(tmpB);
    }

    for(int index = 0; index < zeroLocations.size(); index++)
    {
        vector<vector<int>> target = preBFS(index ,zeroLocations.size());
        vector<vector<int>> vCopy;

        for(int i = 0; i < target.size(); i++)
        {
            vCopy = v;
            for(int j = 0; j < target[i].size(); j++)
            {
                vCopy[zeroLocations[target[i][j]].first][zeroLocations[target[i][j]].second] = 1;
            }

            foo = bfs(vCopy, visit);
            if( answer < foo)
            {
                answer = foo;
                dd = vCopy;
            }
        }
    }

    cout << answer;
}

vector<vector<int>> preBFS(int k, int n)
{
    pair<int,vector<int>> front;
    queue<pair<int, vector<int>>> q;
    vector<vector<int>> returnV;

    q.push({0, {k}});

    while(!q.empty())
    {
        front = q.front();
        q.pop();

        if(front.first == 2)
        {
            returnV.push_back(front.second);
        }

        if(front.first < 2)
        {
            for(int index = 0; index < n; index++)
            {
                vector<int> t = front.second;
                bool check = false;

                for(int i = 0; i < t.size(); i++)
                {
                    if(index == t[i])
                    {
                        check = true;
                    }
                }
                
                if(!check)
                {
                    t.push_back(index);
                    q.push({front.first+1, t});
                }
            }
        }
    }
    return returnV;
}

int bfs(vector<vector<int>> v, vector<vector<bool>> visit)
{
    queue<pair<int, int>> q;
    pair<int,int> front;
    int ax, ay, dx, dy;
    int returnVal = 0;

    for(int i = 0; i < start.size(); i++)
    {
        q.push({start[i].first, start[i].second});
        visit[start[i].first][start[i].second] = true;
    }

    while(!q.empty())
    {
        front = q.front();
        q.pop();
        dx = front.first;
        dy = front.second;

        for(int step = 0; step < moving.size(); step++)
        {
            ax = dx + moving[step].first;
            ay = dy + moving[step].second;
            if( (0 <= ax && ax < n) && (0 <= ay && ay < m) )
            {
                if(!visit[ax][ay])
                {
                    if(v[ax][ay] == 0)
                    {
                        v[ax][ay] = 2;
                        q.push({ax,ay});
                    }
                    visit[ax][ay] = true;
                }
            }
        }
    }

    for(auto k : v)
    {
        for(auto m : k)
        {
            if(m == 0)
                returnVal++;
        }
    }

    return returnVal;
}