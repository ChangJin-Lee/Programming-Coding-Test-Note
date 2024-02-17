#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    vector<int> v;
    int n = 0;
    int m = 0;
    int input = 0;

    cin >> n >> m;

    for(int index = 0; index < n; index++)
    {
        for(int innerIndex = 0; innerIndex < m; innerIndex++)
        {
            cin >> input;
            v.push_back(input);
        }
    }

    for(int index = 0; index < n; index++)
    {
        for(int innerIndex = 0; innerIndex < m; innerIndex++)
        {
            cin >> input;
            v[index*m+innerIndex] += input;
        }
    }
    
    for(int index = 0; index < n; index++)
    {
        for(int innerIndex = 0; innerIndex < m; innerIndex++)
        {
            cout << v[index*m+innerIndex] << " ";
        }
        cout << "\n";
    }
}

