#include <iostream>
#define fastcpp ios::sync_withstdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std; 

long Factorial(long n);

int main()
{
    int n = 0;

    cin >> n;

    cout << Factorial(n);
}

long Factorial(long n)
{
    if(n <= 1)
    {
        return 1;
    }

    return Factorial(n - 1) * n;
}