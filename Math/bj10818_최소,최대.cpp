#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int input;
    vector<int> v;
    cin >> n;
    for (int index=0; index < n; index++){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    cout << v.front() << " " << v.back();
}