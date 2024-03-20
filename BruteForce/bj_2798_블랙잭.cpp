#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main()
{
    fastcpp;
    int n,m;
    int answer = 0;
    vector<int> cards;

    cin >> n >> m;

    cards.assign(n,0);

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(cards[i] + cards[j] > m)
                break;
            for (int k = j+1; k < n; k++)
            {
                int sums = cards[i] + cards[j] + cards[k];
                if(sums <= m && sums > answer)
                {
                    answer = sums;
                }
                else if (sums > m)
                {
                    break;
                }
            }
        }
    }

    cout << answer;
}