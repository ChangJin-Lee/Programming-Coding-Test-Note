#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, x;
    int input;
    vector<int> v;
    cin >> n >> x;
    for (int index=0; index < n; index++){
        cin >> input;
        v.push_back(input);
    }
    for (int index=0; index < n; index++){
        if(x > v[index]){
            cout << v[index] << " ";
        }
    }
}