#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// 재귀로 풀면 안됨. 45% 부근에서 시간초과.
// n개의 집을 칠하는 최소 비용이 드는 경우를 f(n) 이라고 하자.
// f(n) = 2 * f(n-1)

// f(n-1)
//          r - g b
//          g - r b
//          b - r g
// int dp(vector<vector<int>> &v, int cur, int n);

int main()
{
    fastcpp;
    int n = 0;
    int r,g,b;
    vector<vector<int>> v;
    vector<vector<int>> dp;
    vector<int> tmp;

    cin >> n;
    for(int index = 0; index < n; index++)
    {
        tmp.clear();
        r = g = b = 0;
        cin >> r >> g >> b;
        tmp.push_back(r);
        tmp.push_back(g);
        tmp.push_back(b);
        v.push_back(tmp);
        dp.push_back(vector<int> {0,0,0});
    }
    
    dp[0] = v[0];

    for(int index = 1; index < n; index++)
    {
        dp[index][0] = min(dp[index-1][1], dp[index-1][2]) + v[index][0];
        dp[index][1] = min(dp[index-1][0], dp[index-1][2]) + v[index][1];
        dp[index][2] = min(dp[index-1][1], dp[index-1][0]) + v[index][2];
    }
    
    cout << *min_element(dp[n-1].begin(), dp[n-1].end());
    // cout << min({dp(v, 0, n-1), dp(v, 1, n-1), dp(v, 2, n-1)});
}

// int dp(vector<vector<int>> &v, int cur, int n)
// {
//     int l, r;
//     if(n < 0)
//     {
//         return 0;
//     }

//     if(cur == 0)
//     {
//         l = 1;
//         r = 2;
//     }
//     else if( cur == 1)
//     {
//         l = 0;
//         r = 2;
//     }
//     else if ( cur == 2)
//     {
//         l = 0;
//         r = 1;
//     }
    
//     return (min(dp(v, l, n-1) + v[n][cur], dp(v, r, n-1) + v[n][cur]));
// }