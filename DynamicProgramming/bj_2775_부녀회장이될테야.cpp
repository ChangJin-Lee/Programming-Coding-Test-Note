#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    vector<vector<int>> v(15,vector<int>(15,0));
    int t,k,n;

    for(int i = 1; i < 15; i++)
    {
        v[0][i] = i;
    }

    for(int i = 1; i <= 14; i++)
    {
        for(int j = 1; j < 15; j++)
        {
            for(int k = 1; k <= j; k++) 
            {
                v[i][j] += v[i-1][k];
            }
        }
    }

    cin >> t;

    while(t--)
    {
        cin >> k >> n;

        cout << v[k][n] << "\n";
    }
}