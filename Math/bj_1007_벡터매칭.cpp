#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void SetInit(double &minVal, vector<pair<int,int>> &v);
double calculateDistance(int n, vector<pair<int,int>> v);
void dfs(int n, int k, int start, double &minVal, vector<pair<int,int>> v);

vector<bool> visit(21,false);

int main()
{
    fastcpp;
    int t = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    double minVal = 500000001;
    vector<pair<int, int>> v;

    cin >> t;
    while(t--)
    {
        SetInit(minVal, v);
        cin >> n;
        for(int innerIndex = 0; innerIndex < n; innerIndex++)
        {
            cin >> x >> y;
            v.push_back({x,y});
        }
        dfs(n, n/2, 0, minVal, v);
        cout << fixed;
        cout.precision(10);
        cout << minVal << "\n";
    }
}

void SetInit(double &minVal, vector<pair<int,int>> &v)
{
    for(int index = 0; index < visit.size(); index++)
    {
        visit[index] = false;
    }
    v.clear();
    minVal = 500000001;
}

double calculateDistance(int n, vector<pair<int,int>> v)
{
    double x = 0;
    double y = 0;
    for(int index = 0; index < n; index++)
    {
        if(visit[index])
        {
            x += v[index].first;
            y += v[index].second;
        }
        else
        {
            x -= v[index].first;
            y -= v[index].second;
        }
    }
    
    return sqrt(x*x + y*y);
}

void dfs(int n, int k, int start, double &minVal, vector<pair<int,int>> v)
{
    if(k == 0)
    {
        minVal = min(minVal, calculateDistance(n, v));
    }
    else
    {
        for(int index = start; index < n; index++)
        {
            if(!visit[index])
            {
                visit[index] = true;
                dfs(n, k-1, index, minVal, v);
                visit[index] = false;
            }
        }
    }
}
