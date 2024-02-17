#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int input = 0;
    int maxVal = -1;
    int p = 0;
    int q = 0;

    for(int row = 0; row < 9; row++)
    {
        for(int column = 0; column < 9; column++)
        {
            cin >> input;
            if(maxVal < input)
            {
                maxVal = input;
                p = row+1;
                q = column+1;
            }
        }
    }

    cout << maxVal << "\n" << p << " " << q << "\n";
}

