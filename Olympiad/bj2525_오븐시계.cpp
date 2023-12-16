#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int hour, minute, cookingTime;
    int divideFactor;
    cin >> hour >> minute >> cookingTime;
    
    divideFactor = minute + cookingTime;
    hour += divideFactor / 60;
    minute = divideFactor % 60;
    cout << hour % 24 << " " << minute;
}