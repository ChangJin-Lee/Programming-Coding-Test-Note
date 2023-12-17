#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int input;
    int searchFactor;
    int answer = 0;
    vector<int> v;
    cin >> n;
    for (int index=0; index < n; index++){
        cin >> input;
        v.push_back(input);
    }
    cin >> searchFactor;
    for (int index=0; index < n; index++){
        if(searchFactor == v[index]){
            answer++;
        }
    }
    cout << answer;
}