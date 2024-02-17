#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int input;
    int duplicateFactor = 0;
    int cumulativePrize = 0;
    int targetFactor = 0;
    vector<int> dices;
    for(int index=0; index<3; index++){
        cin >> input;
        dices.push_back(input);
    }
    
    sort(dices.begin(), dices.end());
    reverse(dices.begin(), dices.end());
    
    for(int index=1; index<3; index++){
        if(dices[index] == dices[index-1]){
            duplicateFactor += 1;
            targetFactor = dices[index];
        }
    }
    
    switch (duplicateFactor)
    {
    case 0:
        cumulativePrize = dices[0]*100;
        break;
    case 1:
        cumulativePrize = 1000 + targetFactor*100;
        break;
    case 2:
        cumulativePrize = 10000 + targetFactor*1000;
        break;    
    default:
        break;
    }

    cout << cumulativePrize;
}