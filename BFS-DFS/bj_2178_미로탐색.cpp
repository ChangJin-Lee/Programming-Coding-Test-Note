#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visit;
pair<int,int> movable[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void bfs();

int main()
{
    string input;

    cin >> n >> m;

    map.assign(n, vector<int>(m));
    visit.assign(n, vector<bool>(m));

    for(int i = 0; i < n; i++)
    {
        cin >> input;

        for(int j = 0; j < m; j++)
        {
            map[i][j] = int(input[j]) - int('0');
        }
    }

    bfs();
}

void bfs()
{
    queue<tuple<int,int,int>> q;
    int answer = 0;

    visit[0][0] = true;
    q.push({0,0,1});
    
    while(!q.empty())
    {
        tuple<int,int,int> front = q.front();
        q.pop();

        if(get<0>(front) == n-1 && get<1>(front) == m-1)
        {
            answer = get<2>(front);
            break;
        }
        
        for(auto dAxis : movable)
        {
            tuple<int,int,int> nextPosition;
            get<0>(nextPosition) = get<0>(front) + dAxis.first;
            get<1>(nextPosition) = get<1>(front) + dAxis.second;
            get<2>(nextPosition) = get<2>(front);

            if(get<0>(nextPosition) >= 0 && get<0>(nextPosition) < n && get<1>(nextPosition) >= 0 && get<1>(nextPosition) < m)
            {
                if(!visit[get<0>(nextPosition)][get<1>(nextPosition)] && map[get<0>(nextPosition)][get<1>(nextPosition)] == 1)
                {
                    visit[get<0>(nextPosition)][get<1>(nextPosition)] = true;
                    get<2>(nextPosition)++;
                    q.push(nextPosition);
                }
            }
        }

    }

    cout << answer;
}