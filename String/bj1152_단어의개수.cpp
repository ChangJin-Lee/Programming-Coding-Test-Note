#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    string input;
    int answer = 0;
    getline(cin, input);
    if (input.size() == 1 && input[0] == ' ')
    {
        cout << '0';
    }
    else
    {
        for (int index = 1; index < input.size() - 1; index++)
        {
            if (input[index] == ' ')
            {
                answer += 1;
            }
        }
        cout << answer + 1;
    }
}
