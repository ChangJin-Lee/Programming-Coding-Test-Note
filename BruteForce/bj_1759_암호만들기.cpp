#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

bool CheckCondition(int idx);
void BackTracking(vector<int> words, int depth);

int l, c;
vector<char> passwords;
vector<vector<int>> answers;

int main()
{
    fastcpp;

    cin >> l >> c;

    passwords.assign(c,'a');

    for(int i = 0; i < c; i++)
    {
        cin >> passwords[i];
    }

    sort(passwords.begin(), passwords.end());

    for(int i = 0; i < c; i++)
        BackTracking({i},0);

    for(auto answer : answers)
    {
        bool check = false;
        int ContancesCnt = 0;
        for(auto an : answer)
        {
            if(CheckCondition(an))
                check = true;
            else
                ContancesCnt++;
        }

        if(check && ContancesCnt >= 2)
        {
            for(auto an : answer)
            {
                cout << passwords[an];
            }
            cout << "\n";
        }
    }
}

bool CheckCondition(int idx)
{
    if(passwords[idx] == 'a' || 
        passwords[idx] == 'e' || 
        passwords[idx] == 'i' || 
        passwords[idx] == 'o' || 
        passwords[idx] == 'u')
        {
            return true;
        }
    
    return false;
}


void BackTracking(vector<int> words, int depth)
{
    if(depth >= l - 1)
    {
        answers.push_back(words);
    }
    else if (depth < l - 1)
    {
        for(int i = words[depth] + 1; i < c; i++)
        {
            vector<int> v = words;
            v.push_back(i);
            BackTracking(v , depth+1);
        }
    }
}