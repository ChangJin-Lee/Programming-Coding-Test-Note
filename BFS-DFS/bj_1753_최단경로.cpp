#include <iostream>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int maxValue = 10000001;
vector<vector<pair<int,int>>> graph;
vector<int> dp;

void dijkstra(int k);

int main()
{
    fastcpp;
    int v,e,k,u,w;
    
    cin >> v >> e >> k;

    graph.assign(v+1, vector<pair<int,int>>());
    dp.assign(v+1,maxValue);

    for(int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(k);

    for(int i = 1; i < dp.size(); i++)
    {
        if(dp[i] == maxValue)
            cout << "INF\n";
        else
            cout << dp[i] << "\n";
    }
}

void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dp[start] = 0;
    pq.push({0,start});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int curVertex = pq.top().second;
        pq.pop();
        
        if(dp[curVertex] < distance) continue;

        for(auto& edge : graph[curVertex])
        {
            int next = edge.first;
            int nextD = distance + edge.second;

            if(nextD < dp[next])
            {
                dp[next] = nextD;
                pq.push({nextD,next});
            }
        }
        
    }
    
}