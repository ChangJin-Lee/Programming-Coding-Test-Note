#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    string input;
    int answer = 0;
    cin >> n >> input;
    for (int index=0; index < n; index++){
        answer += int(input[index])-48;
    }
    cout << answer << "\n";
}

