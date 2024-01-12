#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    cin >> n;
    for (int index = 1; index <= n; index++)
    {
        for (int Kindex = 0; Kindex < n-index; Kindex++)
        {
            cout << " ";
        }
        for (int Kindex = 0; Kindex < 2 * index - 1; Kindex++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int index = n-1; index > 0; index--)
    {
        for (int Kindex = 0; Kindex < n-index; Kindex++)
        {
            cout << " ";
        }
        for (int Kindex = 0; Kindex < 2 * index - 1; Kindex++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
