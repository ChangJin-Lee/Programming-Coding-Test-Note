#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

vector<bool> visit;

void dfs(vector<pair<int, vector<int>>> &v, int cur);
void bfs(vector<pair<int, vector<int>>> &v, int cur);

int main()
{
    fastcpp;
    int n, m, start;
    int a, b;
    vector<pair<int, vector<int>>> v;

    cin >> n >> m >> start;

    for(int index = 0; index < n; index++)
    {
        v.push_back({index, {}});
        visit.push_back(false);
    }

    while(m--)
    {
        cin >> a >> b;
        v[a-1].second.push_back(b-1);
        v[b-1].second.push_back(a-1);
    }

    for(int index = 0; index < n; index++)
    {
        sort(v[index].second.begin(), v[index].second.end());
    }

    dfs(v, start-1);
    cout << "\n";
    bfs(v, start-1);
}

void dfs(vector<pair<int, vector<int>>> &v, int cur)
{
    if(!visit[cur])
        cout << cur + 1 << " ";

    visit[cur] = true;

    for(int index = 0; index < v[cur].second.size(); index++)
    {
        if(!visit[v[cur].second[index]])
            dfs(v, v[cur].second[index]);
    }
}

void bfs(vector<pair<int, vector<int>>> &v, int cur)
{
    int front;
    queue<int> q;

    visit[cur] = false;
    cout << cur+1 << " ";
    q.push(cur);

   while(!q.empty())
    {
        front = q.front();
        q.pop();

        for(int index = 0; index < v[front].second.size(); index++)
        {
            if(visit[v[front].second[index]])
            {
                cout << v[front].second[index]+1 << " ";
                q.push(v[front].second[index]);
                visit[v[front].second[index]] = false;
            }
        }
    }
}