#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int a,b;
    cin >> n;
    for (int index=0; index < n; index++){
        cin >> a >> b;
        cout << "Case #" << index+1 << ": " << a+b << "\n";
    }
}