#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

// bfs라서 완전탐색으로 한거처럼 보일수도있는데 
// n == 1 일때 1, 2, 3
// n == 2 일때 12, 13, 21, 23, 31, 32
// 이렇게 모든 경우를 보지않고 정확히 n-1인 경우만 수를 봤으니 가지치기가 된 걸로 볼 수 있다

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n;
vector<vector<int>> bfs(vector<int> &exponent, vector<int> &startPoints);

int main()
{
    fastcpp;
    vector<int> startPoints;
    int minAnswer = 2000000001;
    int maxAnswer = -2000000001;
    vector<int> a;
    vector<int> exponent;
    vector<vector<int>> combinations;

    cin >> n;

    a.assign(n,0);
    exponent.assign(4,0);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < 4; i++)
    {
        cin >> exponent[i];
        if(exponent[i] >= n-1)
        {
            exponent[i] = n-1;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(exponent[i] > 0)
        {
            startPoints.push_back(i);
        }
    }

    combinations = bfs(exponent, startPoints);

    for(auto combination : combinations)
    {
        vector<int> target = a;
        for(int i = 1; i < n; i++)
        {
            switch (combination[i-1])
            {
            case 0:
                target[i] = target[i-1] + target[i];
                break;
            case 1:
                target[i] = target[i-1] - target[i];
                break;
            case 2:
                target[i] = target[i-1] * target[i];
                break;
            case 3:
                if(target[i-1] == 0)
                    target[i] = 0;
                else
                    target[i] = target[i-1] / target[i];
                break;
            default:
                break;
            }
        }

        minAnswer = min(minAnswer, target[n-1]);
        maxAnswer = max(maxAnswer, target[n-1]);
    }

    cout << maxAnswer << "\n";
    cout << minAnswer << "\n";
}

vector<vector<int>> bfs(vector<int> &exponent, vector<int> &startPoints)
{
    // 조합 경우, 레벨
    // ex) +-x, 3
    queue<pair<vector<int>, int>> q;
    vector<vector<int>> returnV;
    
    for(auto startPoint : startPoints)
    {
        vector<int> t;
        t.push_back(startPoint);
        q.push({t, 1});
    }

    while(!q.empty())
    {
        vector<int> c = q.front().first;
        int level = q.front().second;
        q.pop();

        if(level == n-1)
        {
            returnV.push_back(c);
        }
        else
        {
            for(int i = 0; i < 4; i++)
            {
                int count = 0;
                for(auto w : c)
                {
                    if(w == i)
                    {
                        count++;
                    }
                }
                if(count < exponent[i])
                {
                    vector<int> o = c;
                    o.push_back(i);
                    q.push({o,level+1});
                }
            }
        }
    }

    return returnV;
}