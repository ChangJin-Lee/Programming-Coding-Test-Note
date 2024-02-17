#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    cin >> n;
    for (int index=0; index < n/4; index++){
        cout << "long ";
    }
    cout << "int" << endl;
}