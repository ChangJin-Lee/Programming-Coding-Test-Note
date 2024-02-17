#include <iostream>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    queue<int> q;

    cin >> n;

    for(int index = 0; index < n; index++)
    {
        q.push(index+1);
    }

    while(q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}