#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n;
    vector<long long> dp;

    cin >> n;

    dp.assign(91,0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for(int i = 4; i <= 90; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}

// 101010101

// 1 1 2 

// 1

// 10

// 101
// 100


// 1010
// 1000
// 1001


// 10100
// 10101
// 10000
// 10001
// 10010


// 101001
// 100001
// 100101
// 101000
// 101010
// 100000
// 100010
// 100100