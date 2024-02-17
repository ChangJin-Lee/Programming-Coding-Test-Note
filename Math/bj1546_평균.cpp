#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    float input;
    float answer = 0;
    float max = 0;
    cin >> n;
    for (int index=0; index < n; index++){
        cin >> input;
        if (input > max){
            max = input;
        }
        answer += input;
    }
    cout << ((answer / max) * 100 ) / n;
}

