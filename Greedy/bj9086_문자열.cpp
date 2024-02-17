#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int t;
    string input;
    cin >> t;
    for (int index=0; index < t; index++)
    {
        cin >> input;
        cout << input.front() << input.back() << "\n";
    }
}