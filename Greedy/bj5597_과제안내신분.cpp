#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, m;
    int input;
    vector<bool> v(30,false);
    for (int index=0; index < 28; index++){
        cin >> input;
        v[input-1] = true;
    }
    for (int index=0; index < v.size(); index++){
        if(!v[index]){
            cout << index+1 << "\n";
        }
    }
}

