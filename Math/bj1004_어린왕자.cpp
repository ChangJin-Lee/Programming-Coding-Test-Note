#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int T, n;           // TC, planetary system count
    int x0, y0, x1, y1; // Starting point, End point
    int cx, cy, r;      // circle axis, radius

    cin >> T;

    while (T--)
    {
        int answer = 0;
        cin >> x0 >> y0 >> x1 >> y1;
        cin >> n;
        while (n--)
        {
            cin >> cx >> cy >> r;
            int distance1 = pow((x0 - cx), 2) + pow((y0 - cy), 2);
            int distance2 = pow((x1 - cx), 2) + pow((y1 - cy), 2);
            int powR = pow(r, 2);
            if (!(distance1 <= powR && distance2 <= powR))
            {
                if (distance1 <= powR || distance2 <= powR)
                {
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
}