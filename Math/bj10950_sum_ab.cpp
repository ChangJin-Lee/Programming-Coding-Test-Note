#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int t, a, b;
    cin >> t;
    for (int index = 0 ; index < t; index++){
        cin >> a >> b;
        cout << a+b << endl;
    }
}