#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    vector<int> dp;

    cin >> n;

    dp.assign(n+1,0);

    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i < n+1; i++)
    {
        dp[i] = (2 * dp[i-2] + dp[i-1]) % 10007;
    }

    cout << dp[n];
}