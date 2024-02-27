#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

bool bfs(vector<bool> &visited, vector<vector<int>> &graph, int start);

int main()
{
    fastcpp;
    int n, v, e, u;
    
    cin >> n;

    while(n--)
    {
        cin >> v >> e;
        
        vector<bool> visited(v+1,false);
        vector<vector<int>> graph(v+1, vector<int>());
        bool check = false;

        for(int i = 0; i < e; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int start = 1; start < visited.size(); start++)
        {
            if(!visited[start])
            {
                if(!bfs(visited, graph, start))
                {
                    cout << "NO\n";
                    check = true;
                    break;
                }
            }
        }

        if(!check)
        {
            cout << "YES\n";
        }
        
    }
}

bool bfs(vector<bool> &visited, vector<vector<int>> &graph, int start)
{
    queue<pair<int,int>> q; // front : 현재 방문 노드, second : level
    vector<vector<int>> levelVertex(20001,vector<int>());

    levelVertex.push_back({start});
    visited[start] = true;
    q.push({start,0});

    while(!q.empty())
    {
        int vertex = q.front().first;
        int level = q.front().second;
        q.pop();

        for(auto component : graph[vertex])
        {
            if(!visited[component])
            {
                levelVertex[level+1].push_back(component);
                q.push({component,level + 1});
                visited[component] = true;
            }
            else
            {
                if(find(levelVertex[level].begin(), levelVertex[level].end(), component) != levelVertex[level].end())
                    return false;
            }
        }
    }

    return true;
}