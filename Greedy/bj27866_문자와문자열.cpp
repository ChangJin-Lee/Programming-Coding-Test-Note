#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    string S;
    int i;
    cin >> S >> i;
    cout << S.at(i-1);
}