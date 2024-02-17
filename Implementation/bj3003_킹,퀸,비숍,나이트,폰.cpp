#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    vector<int> chess = {1,1,2,2,2,8};
    int input;
    for (int index=0; index<6; index++)
    {
        cin >> input;
        cout << chess[index] - input << " ";
    }
}
