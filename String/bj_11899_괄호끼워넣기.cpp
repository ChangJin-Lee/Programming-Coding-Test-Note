#include <iostream>
#include <stack>
#include <string>
#define fastcpp ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    fastcpp;
    string input;
    stack<char> stack;

    cin >> input;

    for(int index = 0; index < input.size(); index++)
    {
        if(input[index] == ')')
        {
            if(stack.empty())
            {
                stack.push(input[index]);
            }
            else
            {
                if(stack.top() == '(')
                {
                    stack.pop();
                }
                else
                {
                    stack.push(input[index]);
                }
            }
        }
        else
        {
            stack.push(input[index]);
        }
    }

    cout << stack.size();
}