#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int repeat;
    string input;
    cin >> n;
    for (int index=0; index < n; index++)
    {
        cin >> repeat >> input;
        for (int innerIndex=0; innerIndex < input.size(); innerIndex++)
        {
            for (int inInnerIndex=0; inInnerIndex< repeat; inInnerIndex++)
            {
                cout << input[innerIndex];
            }
        }
        cout << "\n";
    }
}

