#include <iostream>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullpt), cout.tie(nullptr);

using namespace std;

int main()
{
    int n;
    bool check = false;

    cin >> n;


    for(int i = 0; i < n/3 + 1; i++)
    {
        for(int j = 0; j < n/5 + 1; j++)
        {
            if(n == 3*i + 5*j)
            {
                cout << i+j;
                check = true;
                break;
            }
                
        }
        if(check)
            break;
    }

    if(!check)
        cout << -1;
}