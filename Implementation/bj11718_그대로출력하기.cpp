#include <iostream>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    string input;
    while (getline(cin, input))
    {
        cout << input << endl;
    }
}
