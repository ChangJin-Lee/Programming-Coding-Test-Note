#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    long long answer = 0;
    vector<vector<long long>> dp;

    cin >> n;

    dp.assign(101,vector<long long>(10,0));

    for(int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i < n+1; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j = 1; j < 9; j++)
        {
            dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1])  % 1000000000;
        }
    }
    
     for(int i = 0; i < 10; i++)
    {
        answer = (answer + dp[n][i]) % 1000000000;
    }

    cout << answer;

}