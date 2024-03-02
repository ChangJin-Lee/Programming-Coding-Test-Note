#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

vector<int> dp;

void solution(int k);

int main()
{
    fastcpp;
    int n;

    cin >> n;
    
    dp.assign(n+1, 0);

    for(int i = 2; i < n+1; i++)
        solution(i);
    cout << dp[n];
}

void solution(int k)
{
    if(k % 6 == 0)
    {
        dp[k] = min({dp[k/3], dp[k/2], dp[k-1]}) + 1;
    }
    else if(k % 3 == 0)
    {
        dp[k] = min(dp[k/3], dp[k-1]) + 1;
    }
    else if(k % 2 == 0)
    {
        dp[k] = min(dp[k/2], dp[k-1]) + 1;
    }
    else
    {
        dp[k] = dp[k-1] + 1;
    }
}