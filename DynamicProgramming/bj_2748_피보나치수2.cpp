#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    vector<long long> dp;

    cin >> n;

    dp.assign(n+1,0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n+1; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}