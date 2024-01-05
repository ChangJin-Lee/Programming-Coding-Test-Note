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
    int integerToA = (int)'A';
    int stringUnit = 0;
    int answer = 0;
    string input;
    cin >> input;
    for (int index = 0; index < input.size(); index++)
    {
        stringUnit = (int)input[index] - integerToA;

        if (stringUnit < (int)'P' - (int)'A')
        {
            answer += (stringUnit / 3 ) + 3;
        }
        else if ( (int)'P' - (int)'A' <= stringUnit && stringUnit < (int)'T' - (int)'A')
        {
            answer += 8;
        }
        else if ( (int)'T' - (int)'A' <= stringUnit && stringUnit < (int)'W' - (int)'A' )
        {
            answer += 9;
        }
        else
        {
            answer += 10;
        }
    }
    
    cout << answer;
}
