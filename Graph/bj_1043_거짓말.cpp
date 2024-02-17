#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void SetattendLie(int Count, vector<vector<int>> &attendLie, vector<bool> &knowLie);
int HasLier(vector<vector<int>> &v, vector<bool> &knowLie);
void dvide(vector<vector<int>> &attendLie, vector<bool> &knowLie);

int main()
{
    fastcpp;
    int n = 0;
    int m = 0;
    int Count = 0;
    int Number = 0;
    vector<bool> knowLie;
    vector<vector<int>> attendLie;
    
    cin >> n >> m;
    
    for(int index = 0; index < n; index++)
    {
        knowLie.push_back(false);
    }
    
    cin >> Count;

    for(int index = 0; index < Count; index++)
    {
        cin >> Number;
        knowLie[Number-1] = true;
    }

    for(int index = 0; index < m; index++)
    {
        cin >> Count;
        SetattendLie(Count, attendLie, knowLie);
    }

    dvide(attendLie, knowLie);

    cout << attendLie.size();
}

void SetattendLie(int Count, vector<vector<int>> &attendLie, vector<bool> &knowLie)
{
    int number;
    vector<int> tmp;
    for(int index = 0; index < Count; index++)
    {
        cin >> number;
        tmp.push_back(number-1);
    }
    attendLie.push_back(tmp);
}

int HasLier(vector<vector<int>> &v, vector<bool> &knowLie)
{
    for(int index = 0; index < v.size(); index++)
    {
        for(int innerIndex = 0; innerIndex < v[index].size(); innerIndex++)
        {
            if(knowLie[v[index][innerIndex]])
                return index;
        }
    }
    return -1;
}

void dvide(vector<vector<int>> &attendLie, vector<bool> &knowLie)
{
    int index = 0;
    do
    {
        index = HasLier(attendLie, knowLie);
        if(index != -1)
        {
            for(int i = 0; i < attendLie[index].size(); i++)
            {
                knowLie[attendLie[index][i]] = true; 
            }
            attendLie.erase(attendLie.begin() + index);
        }
    } while (index != -1);
}