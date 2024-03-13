#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n,m;
    long long num;
    vector<int> cards;

    cin >> n;
    cards.assign(n,0);
    for(int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> num;
        bool check = false;
        int left = 0;
        int right = n-1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(cards[mid] < num)
            {
                left = mid + 1;
            }
            else if (cards[mid] > num)
            {
                right = mid - 1;
            }
            else
            {
                check = true;
                break;
            }
        }

        if(check)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

}