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
    string input;
    int b= 0;
    int answer = 0;
    int roundNum = 1;
    cin >> input >> b;

    for(int index = input.length() - 1; index >= 0; index--)
    {
        if('0' <= input[index] && input[index] <= '9')
        {
            answer += (int)(input[index] - '0') * roundNum;
        }
        else
        {
            answer += ((int)(input[index] - 'A') + 10) * roundNum;
        }

        roundNum *= b;
    }

    cout << answer;
}