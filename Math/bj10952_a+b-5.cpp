#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int a, b;
    while(true){
        cin >> a >> b;
        if(a==0 && b==0){
            break;
        }
        cout << a+b << "\n";
    }
}