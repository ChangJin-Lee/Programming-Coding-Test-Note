#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void InitVector(vector<vector<int>> &v);
void SetVectorToOne(vector<vector<int>> &v, int x, int y);
int GetVectorOneCount(vector<vector<int>> v);

int main()
{
    fastcpp;
    vector<vector<int>> v;
    int n = 0;
    int x = 0;
    int y = 0;
    InitVector(v);

    cin >> n;
    for(int index = 0; index < n; index++)
    {
        cin >> x >> y;
        SetVectorToOne(v, x, y);
    }

    cout << GetVectorOneCount(v);
}

void InitVector(vector<vector<int>> &v)
{
    vector<int> tempV(100,0);
    for(int column = 0; column < 100; column++)
    {
        v.push_back(tempV);
    }
}

void SetVectorToOne(vector<vector<int>> &v, int x, int y)
{
     for(int column = x; column < x + 10; column++)
        {
            for(int row = y; row < y + 10; row++)
            {
                if (column < 100 && row < 100)
                {
                    v[column][row] = 1;
                }
            }
        }
}

int GetVectorOneCount(vector<vector<int>> v)
{
    int returnVal = 0;
    for(int column = 0; column < 100; column++)
        {
            for(int row = 0; row < 100; row++)
            {
                if(v[column][row] == 1)
                {
                    returnVal++;
                }
            }
        }
    return returnVal;
}