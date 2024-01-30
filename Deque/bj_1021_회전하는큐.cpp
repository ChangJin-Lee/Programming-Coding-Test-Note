#include <iostream>
#include <algorithm>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, m, left, right, tmp;
    int cur = 0;
    int answer = 0;
    deque<int> q;

    cin >> n >> m;

    for(int index = 0; index < n; index++)
    {
        q.push_back(index+1);
    }

    while(m--)
    {
        cin >> tmp;
        left = find(q.begin(), q.end(), tmp) - q.begin();
        right = q.size() - left;
        
        if(left < right)
        {
            while(left--)
            {
                cur = q.front();
                q.pop_front();
                q.push_back(cur);
                answer++;
            }
        }
        else
        {
            while(right--)
            {
                cur = q.back();
                q.pop_back();
                q.push_front(cur);
                answer++;
            }
        }

        q.pop_front();
    }

    cout << answer;
}