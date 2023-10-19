#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int space[1000001][1000001] = {0,};

void setAxis(int x, int y, int &xMax, int &yMax, int &xMin, int &yMin)
{
    xMax = max(x,xMax);
    yMax = max(y,yMax);
    xMin = min(x, xMin);
    yMin = min(y, yMin);
}

int main() {
    int n;  // number of tree;
    int x, y, p;
    int xMax = 0;
    int yMax = 0;
    int xMin = 1000001;
    int yMin = 1000001;

    cin >> n;

    while (n--)
    {
        cin >> x >> y >> p;
        // 1. 최대 좌표와 최소 좌표를 구하기.
        setAxis(x, y, xMax, yMax, xMin, yMin);

        // 2. 경우의 수 나누기
        //  a. 직사각형 경계선의 나무를 벌목하는 경우
        //  b. 직사각형 내부의 나무를 벌목하는 경우
        //  c. 직사각형 경계선과 내부의 나무를 둘다 벌목하는 경우
            
        // 만들 수 있는 나무의 개수가 큰 나무를 집중하는게 먼저인가?
        // 아니면  최대 or 최소 좌표를 없애는게 먼저인가? 
    }
    cout << xMax << yMax << xMin << yMin << endl ;
}