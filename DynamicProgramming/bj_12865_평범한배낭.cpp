#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    vector<int> weight, value;
    vector<vector<int>> dp;
    int answer = 0;
    int n,k,w,v;

    cin >> n >> k;

    weight.assign(n+1, 0);
    value.assign(n+1, 0);
    dp.assign(n+1, vector<int>(k+1,0));

    for(int i = 1; i <= n; i++)
    {
        cin >> w >> v;
        weight[i] = w;
        value[i] = v;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - weight[i] >= 0) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k];
}