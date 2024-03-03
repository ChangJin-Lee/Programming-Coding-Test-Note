#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    bool check = false;
    vector<int> dp;
    vector<int> stair;

    cin >> n;

    dp.assign(n+1,0);
    stair.assign(n+1,0);

    for(int i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }

    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i] = stair[i] + max(dp[i-2], dp[i-3] + stair[i-1]);
    }

    cout << dp[n];
}