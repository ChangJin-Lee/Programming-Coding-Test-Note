#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n;
    int input;
    priority_queue<int> pq;

    cin >> n;

    while(n--)
    {
        cin >> input;

        if(input == 0)
        {
            if(pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << -pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(-input);
        }
    }
}

