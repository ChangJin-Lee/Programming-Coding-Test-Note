#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    int answer = 0;
    vector<int> t, p;
    vector<int> dp;

    cin >> n;

    t.assign(n+1,0);
    p.assign(n+1,0);
    dp.assign(n+1, 0);

    for(int i = 1; i < n+1; i++)
    {
        cin >> t[i] >> p[i];
        dp[i] = p[i];
    }

    for(int i = 1; i < n+1; i++)
    {
        int maxVal = 0;
        if( i + t[i] <= n+1)
        {
            for(int j = 1; j <= i; j++)
            {
                
                if(i - j >= 1)
                {
                    if(j >= t[i-j] && i-j + t[i-j] <= n+1)
                    {
                        maxVal = max(maxVal, dp[i-j]);
                    }
                }
            }
            dp[i] += maxVal;
            answer = max(dp[i], answer);
        }
        //  cout << maxVal << ":" << dp[i] << " ";
    }

    cout << answer;
}