#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int vSize = 'z' - 'a' + 1;
    vector<int> v(vSize, -1);
    string input;
    cin >> input;
    for (int index = 0; index < input.size(); index++){
        int iIndex = int(input[index]) - int('a');
        if(v[iIndex] == -1){
            v[iIndex] = index;
        }
    }
    for( auto k : v){
        cout << k << " ";
    }
}

