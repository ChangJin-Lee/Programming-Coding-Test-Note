#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int reverseInt(int a);

int main()
{
    fastcpp;
    int a, b;
    int answer;
    cin >> a >> b;
    a = reverseInt(a);
    b = reverseInt(b);
    
    answer = (a>b)? a : b;
    cout << answer;
}

int reverseInt(int a)
{
    int ta = a;
    int retrunVal = 0;
    
    for (int index=0; index<3; index++)
    {
        retrunVal += (ta%10)*pow(10,2-index);
        ta = ta / 10;
    }
    return retrunVal;
}