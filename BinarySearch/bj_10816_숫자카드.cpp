#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, m, left, right, mid;
    vector<int> v;
    map<int,int> s;

    cin >> n;

    v.assign(n,0);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(s.find(v[i]) == s.end())
        {
            s[v[i]] = 1;
        }
        else
        {
            s[v[i]]++;
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        if(s.find(target) != s.end())
        {
            cout << s[target] << " ";
        }
        else
            cout << 0 << " ";
    }
}