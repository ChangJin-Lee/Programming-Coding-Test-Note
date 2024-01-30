#include <iostream>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, k, input;
    int cur;
    deque<int> q;

    cin >> n >> k;

    for(int index = 0; index < n; index++)
    {
        cin >> input;
        q.push_back(index+1);
    }

    cout << "<";
    while(!q.empty())
    {
        cur = k-1;
        while(cur--)
        {
            q.push_back(q.front());
            q.pop_front();
        }

        cout << q.front();
        if (q.size()!=1)
            cout << ", ";
        q.pop_front();
    }

    cout << ">";
}