#include <iostream>
#include <cmath>
#define fastcpp ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void cantor(int n)
{
    if(n == 0)
    {
        cout << '-';
        return;
    }
    
    cantor(n - 1);

    for(int index = 0; index < pow(3, n - 1); index++)
    {
        cout << ' ';
    }

    cantor(n - 1);
}

int main()
{
    fastcpp;
    int n = 0; 

    while(cin >> n)
    {
        cantor(n);
        cout << '\n';
    }

    return 0;
}