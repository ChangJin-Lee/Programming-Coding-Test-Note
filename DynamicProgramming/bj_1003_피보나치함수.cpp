#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int t,n;
    vector<int> countZero(41,0);
    vector<int> countOne(41,0);

    countZero[0] = 1;
    countZero[1] = 0;
    countOne[0] = 0;
    countOne[1] = 1;

    for(int i = 2; i < 41; i++)
    {
        countZero[i] = countZero[i-1] + countZero[i-2];
        countOne[i] = countOne[i-1] + countOne[i-2];
    }

    cin >> t;

    while(t--)
    {
        cin >> n; 

        cout << countZero[n] << " " << countOne[n] << "\n";
    }
}