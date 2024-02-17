#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int gcd(int n, int m);
// 2 3 5 7 11 13 17 ...
// m과 나누어 떨어지는 제일 큰 소수를 찾자.

int main()
{
    fastcpp;
    int n = 0;
    int m = 0;
    cin >> n >> m;
    cout << m - gcd(n,m);
}

int gcd(int n, int m)
{
    int tmp = 0;
    while(m!=0)
    {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}