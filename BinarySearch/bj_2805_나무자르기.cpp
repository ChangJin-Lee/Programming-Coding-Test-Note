#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    bool check = false;
    long long left,right,mid,m, sums;
    vector<long long> v;

    cin >> n >> m;

    v.assign(n,0);
    left = 1000001;
    right = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        left = min(left, v[i]);
        right = max(right, v[i]);
    }

    while(left <= right)
    {
        sums = 0;
        mid = (left + right) / 2;

        for(auto k : v)
        {
            if(mid < k)
            {
                sums += k - mid;
            }
        }

        if(sums < m)
        {
            right = mid - 1;
        }
        else if (sums > m)
        {
            left = mid + 1;
        }
        else if ( sums == m)
        {
            check = true;
            break;
        }
    }

    if(n == 1)
        cout << v[0] - m;
    else if (check == true)
        cout << mid;
    else if (check == false)
    {
        if(sums < m)
        {
            cout << right;
        }
        else if (sums > m)
        {
            cout << mid;
        }
    }
}