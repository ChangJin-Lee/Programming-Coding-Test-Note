#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    cin >> n;
    for (int index = 1; index < 10; index++){
        cout << n << " * " << index << " = " << n*index << endl;
    }
}