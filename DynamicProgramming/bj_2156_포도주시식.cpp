#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    vector<int> v, dp;

    cin >> n;

    v.assign(n+1,0);
    dp.assign(n+1,0);

    for(int i = 1 ; i <= n; i++)
    {
        cin >> v[i];
    }

    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max({v[1] + v[3], v[1] + v[2], v[2] + v[3]});

    for(int i = 4; i <= n; i++)
    {
        dp[i] = max({dp[i-1], dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]});
    }

    cout << dp[n];
}


// 6 10 13 9 8 1

// 6 16 23 28 33



