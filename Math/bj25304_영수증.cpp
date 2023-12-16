#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int cost, number;
    int totalAmount;
    cin >> totalAmount >> n;
    for (int index = 0; index < n; index++){
        cin >> cost >> number;
        totalAmount -= cost*number;
    }
    if(totalAmount == 0){
        cout << "Yes";
    } else {
        cout << "No";
    }
}