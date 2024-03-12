#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, m, left, right, mid;
    vector<int> v;

    cin >> n;

    v.assign(n,0);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cin >> m;

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++)
    {
        int target;
        bool check = true;
        cin >> target;
        left = 0;
        right = n-1;

        while(left <= right)
        {
            mid = (left + right) / 2;
            if(v[mid] < target)
            {
                left = mid + 1;
            }
            else if (v[mid] > target)
            {
                right = mid - 1;
            }
            else if (v[mid] == target)
            {
                check = false;
                break;
            }
        }

        if(!check)
            cout << "1\n";
        else
            cout << "0\n";
    }
}