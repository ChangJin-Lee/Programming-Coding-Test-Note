#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n;
int answer = 20000;
vector<bool> visited;
vector<vector<int>> v;
vector<int> visitedPath;

void dfs(int level, int k);

int main()
{
    int input;
    
    cin >> n;
    
    v.assign(n,vector<int>(n,0));
    visitedPath.assign(n/2,0);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> input;
            v[i][j] = input;
        }
        visited.push_back(false);
    }

    dfs(0,0);
    cout << answer;
}

void dfs(int level, int k)
{
    if(level == n/2)
    {
        vector<int> notVisitedPath;
        int team1 = 0;
        int team2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(find(visitedPath.begin(), visitedPath.end(),i) == visitedPath.end())
            {
                notVisitedPath.push_back(i);
            }
        }

        for(int i = 0; i < n/2; i++)
        {
            for(int j = i + 1; j < n/2; j++)
            {
                team1 += v[visitedPath[i]][visitedPath[j]] + v[visitedPath[j]][visitedPath[i]];
                team2 += v[notVisitedPath[i]][notVisitedPath[j]] + v[notVisitedPath[j]][notVisitedPath[i]];
            }
        }

        if(answer > abs(team1 - team2))
        {
            answer = abs(team1 - team2);
        }
        return ;
    }

    for(int i = k; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            visitedPath[level] = i;
            dfs(level+1, i);
            visited[i] = false;
        } 
        
    }
    
}