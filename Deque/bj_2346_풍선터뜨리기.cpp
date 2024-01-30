#include <iostream>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, input;
    pair<int,int> cur;
    deque<pair<int,int>> q;

    cin >> n;

    for(int index = 0; index < n; index++)
    {
        cin >> input;
        q.push_back({index, input});
    }

    while(!q.empty())
    {
        cur = q.front();
        q.pop_front();
        cout << cur.first+1 << " ";
        if(cur.second > 0)
        {
            cur.second--;
            while(cur.second--)
            {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        else
        {
            while(cur.second++)
            {
                q.push_front(q.back());
                q.pop_back();
            }
        }
    }
}