#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    int cost, number;
    int totalAmount;
    int calculatedTotalAmount;
    cin >> totalAmount >> n;
    for (int index = 0; index < n; index++){
        cin >> cost >> number;
        calculatedTotalAmount += cost*number;
    }
    if(calculatedTotalAmount != totalAmount){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}