#include <iostream>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int fibonacci(int n);

int countZero = 0;
int countOne = 0;

int main()
{
    int t,n;

    cin >> t;

    while(t--)
    {
        cin >> n; 

        fibonacci(n);

        cout << countZero << " " << countOne << "\n";
        countZero = 0;
        countOne = 0;
    }
}


int fibonacci(int n) 
{
    if (n == 0) {
        countZero++;
        return 0;
    } else if (n == 1) {
        countOne++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}