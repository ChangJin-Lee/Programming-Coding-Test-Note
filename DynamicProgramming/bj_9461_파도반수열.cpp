#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int t, input;
    vector<long long> dp(101,0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;

    for(int i = 5; i < 101; i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }

    cin >> t;

    while(t--)
    {
        cin >> input;
        cout << dp[input-1] << "\n";
    }
}