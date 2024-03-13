#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int k,n;
    long long left = 1;
    long long right = 0;
    long long mid, count;
    vector<long long> v;

    cin >> k >> n;

    v.assign(k,0);

    for(int i = 0; i < k; i++)
    {
        cin >> v[i];
        right = max(right, v[i]);
    }

    while(left <= right)
    {
        count = 0;
        mid = (left + right) / 2;

        for(auto l : v)
        {
            count += l / mid;
        }

        if(count < n)
        {
            right = mid - 1;
        }
        else if ( count >= n)
        {
            left = mid + 1;
        }
    }

    if(k == 1)
        cout << v[0] / n;
    else
    {
        if(count < n)
        {
            cout << mid - 1;
        }
        else
            cout << mid;
    }
}