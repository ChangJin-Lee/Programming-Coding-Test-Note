#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void SetVector(vector<vector<bool>> &v, int n);
int GetFriendCount(vector<vector<bool>> &v, int index, int n);

int main()
{
    fastcpp;
    int n;
    int answer = 0;
    int foo = 0;
    vector<vector<bool>> v;
    
    cin >> n;
    for(int index = 0; index < n; index++)
    {
        SetVector(v, n);
    }

    for(int index = 0; index < n; index++)
    {
       foo = GetFriendCount(v, index, n);
       if(answer < foo)
       {
        answer = foo;
       }
    }
    
    cout << answer << "\n";
}

void SetVector(vector<vector<bool>> &v, int n)
{
    vector<bool> tmp;
    char input;
    for(int index = 0; index < n; index++)
    {
        cin >> input;
        tmp.push_back(input == 'Y' ? true : false);
    }
    v.push_back(tmp);
}

int GetFriendCount(vector<vector<bool>> &v, int idx, int n)
{
    vector<bool> visit(n,false);
    vector<pair<int,int>> queue;
    int returnVal = 0;
    pair<int,int> front;

    visit[idx] = true;
    queue.push_back({0, idx});

    while(!queue.empty())
    {
        front = queue.front();
        queue.erase(queue.begin());

        if(front.first < 2)
        {
            for(int index = 0; index < n; index++)
            {
                if(!visit[index])
                {
                    if(v[front.second][index] && index != front.second)
                    {
                        queue.push_back({front.first+1, index});
                        visit[index] = true;
                        returnVal++;
                    }
                }
            }
        }
    }

    return returnVal;
}