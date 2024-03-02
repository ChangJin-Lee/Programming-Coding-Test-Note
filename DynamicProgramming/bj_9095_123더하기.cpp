#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int t, n;
    vector<int> dp(12,0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4; 

    for(int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
}

// dp[i] : i를 1,2,3의 합으로 나타내는 방법

// dp[i+1] = d[i] + 1;

// dp[i+2] = dp[i] + 2;

// dp[i+3] = dp[i] + 4;

// dp[i+4] = dp[i+1] + dp[i+2] + dp[i+3];