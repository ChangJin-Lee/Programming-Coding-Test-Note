// mCn
#include <iostream>

#define fastpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int combination(int n, int r, int arr[][30])
{
    if(n == r || r == 0) 
        return arr[n][r] = 1; 
    else if(arr[n][r] != 0)
        return arr[n][r];
    else 
        return arr[n][r] = combination(n - 1, r - 1, arr) + combination(n - 1, r, arr);
}

int main()
{
    fastpp;
    int t, n, m;
    int arr[30][30] = {0,};
    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        cout << combination(m, n, arr) << "\n";
    }
}