#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

vector<int> v[100001];
vector<bool> visit;
vector<int> p;

void dfs(int k);

int main()
{
    fastcpp;
    int n, a, b;
    
    cin >> n;

    visit.assign(n+1,false);
    p.assign(n+1, 0);

    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    
    dfs(1);
    for(int i = 2; i < n+1; i++)
    {
        cout << p[i] << "\n";
    }
}

void dfs(int k)
{
    visit[k] = true;

    for(auto m : v[k])
    {
        if(!visit[m])
        {
            dfs(m);
            p[m] = k;
        }
    }
}