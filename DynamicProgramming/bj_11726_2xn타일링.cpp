#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    vector<int> dp(1001,0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 3; i < 1001; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) % 10007; 
    }

    cin >> n;

    cout << dp[n];
}