#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int input;
    int maxNumber = 0;
    int maxIndex = 0;
    for (int index=0; index < 9; index++){
        cin >> input;
        if(maxNumber < input){
            maxNumber = input;
            maxIndex = index+1;
        }
    }
    cout << maxNumber << "\n" << maxIndex;
}