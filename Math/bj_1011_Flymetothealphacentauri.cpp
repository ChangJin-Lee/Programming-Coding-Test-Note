#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// n+1 + n(n-1)/2 + n(n-1)/2
// = n^2 + 1
// 2 * n - 1

int main()
{
    fastcpp;
    int t = 0;
    int x = 0;
    int y = 0;
    int distance = 0;
    int maxDistance = 0;
    int answer = 0;

    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        answer = 0;
        distance = y-x;
        maxDistance = sqrt(distance);
        answer += 2 * maxDistance - 1;
        distance -= maxDistance * maxDistance;
        while(distance != 0)
        {
            if(distance - maxDistance >= 0)
            {
                distance -= maxDistance;
                answer++;
            }
            else
            {
                maxDistance--;
            }
        }
        cout << answer << "\n";
    }
}