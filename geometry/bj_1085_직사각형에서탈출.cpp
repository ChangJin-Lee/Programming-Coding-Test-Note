#include <iostream>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int x,y,w,h;

    cin >> x >> y >> w >> h;

    cout << min({x, y, w-x, h-y});
}