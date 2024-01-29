#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int currentProblem = 0;
    int nextProblem = 0;
    vector<int> fixed;
    vector<vector<int>> v;
    priority_queue<int> q;

    for(int index = 0; index < 32001; index++)
    {
        v.push_back({});
        fixed.push_back(0);
    }

    cin >> n >> m;
    for(int index = 0; index < m; index++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        fixed[b]++;
    }

    //  오름차순이기때문에 음의 인덱스를 넣어야한다.
    for(int index = 1; index <= n; index++)
    {
        if(fixed[index] == 0)
        {
            q.push(-index);
        }
    }

    while(!q.empty())
    {
        currentProblem = -q.top();
        q.pop();

        cout << currentProblem << " ";

        for(int index = 0; index < v[currentProblem].size(); index++)
        {
            nextProblem = v[currentProblem][index];
            fixed[nextProblem]--;

            if(fixed[nextProblem] == 0)
                q.push(-nextProblem);
        } 
    }

    cout << "\n";
}

// #############################################################################################
// 금지 법칙 테이블을 만드는 방법
// bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b);

// int main()
// {
//     fastcpp;
//     int n = 0;
//     int m = 0;
//     int a = 0;
//     int b = 0;
//     bool check = false;
//     int targetIndex = -1;
//     pair<int,vector<int>> front;
//     vector<int> tmp;
//     vector<pair<int,vector<int>>> v;
//     vector<int> answer;

//     cin >> n >> m;

//     for(int index = 0; index < n; index++)
//     {
//         v.push_back({index+1,{}});
//     }

//     for(int index = 0; index < m; index++)
//     {
//         cin >> a >> b;
//         v[b-1].second.push_back(a);
//     }

//     sort(v.begin(), v.end(), compare);

//     for(auto k : v)
//     {
//         cout << k.first << " : ";
//         for(auto m : k.second)
//         {
//             cout << m << " ";
//         }
//         cout << "\n";
//     }

//     while(!v.empty())
//     {
//         front = v.front();
//         v.erase(v.begin());

//         for(auto k : v)
//         {
//             cout << k.first << " : ";
//             for(auto m : k.second)
//             {
//                 cout << m << " ";
//             }
//             cout << "\n";
//         }
     
//         for(auto k : answer)
//         {
//             cout << k << " ";
//         }
//         cout << "\n";

//         if(front.second.empty())
//         {
//             answer.push_back(front.first);
//         }
//         else
//         {
//             tmp.clear();
//             targetIndex = -1;

//             for(int aIndex = 0; aIndex < front.second.size(); aIndex++)
//             {
//                 if(find(answer.begin(), answer.end(), front.second[aIndex]) != front.second.end())
//                     tmp.push_back(front.second[aIndex]);
//             }
            
            
//             for(int i = 0; i < tmp.size(); i++)
//             {
//                 int foo = find(answer.begin(), answer.end(), tmp[i]) - answer.begin();
//                 if( targetIndex < foo)
//                     targetIndex = foo;
//             }

//             if(targetIndex == -1)
//             {
//                 check = false;
//                 for(int i = 0; i < answer.size(); i++)
//                 {
//                     if(answer[i] > front.first)
//                     {
//                         answer.insert(answer.begin() + i, front.first);
//                         check = true;
//                         break;
//                     }
//                 }
//                 if(!check)
//                     answer.push_back(front.first);
//             }
//             else
//             {
//                 check = false;
//                 for(int i = targetIndex+1; i < answer.size(); i++)
//                 {
//                     if( answer[i] > front.first)
//                     {
//                         check = true;
//                         answer.insert(answer.begin() + i, front.first);
//                         break;
//                     }
//                 }
//                 if(!check)
//                 {
//                     answer.push_back(front.first);
//                 }
//             }
//         }
//         for(int vIndex = 0; vIndex < n; vIndex++)
//         {
//             for(int i = 0; i < v[vIndex].second.size(); i++)
//             {
//                 if (front.first == v[vIndex].second[i])
//                     v[vIndex].second.erase(v[vIndex].second.begin() + i);
//             }
//         }
//         sort(v.begin(), v.end(), compare);
//     }

//     for(auto k : answer)
//     {
//         cout << k << " ";
//     }
//     cout << "\n";
// }

// bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b)
// {
//     return a.second.size() == b.second.size() ? a.first < b.first : a.second.size() < b.second.size();
// }

// ################################################################################
// 그리디

// bool sortVector(vector<int> &v, int a, int b);

// int main()
// {
//     fastcpp;
//     int n = 0;
//     int m = 0;
//     int a = 0;
//     int b = 0;
//     bool foo;
//     vector<int> v;
//     vector<pair<int,int>> position;

//     cin >> n >> m;

//     for(int index = 0; index < n; index++)
//     {
//         v.push_back(index+1);
//     }

//     for(int index = 0; index < m; index++)
//     {
//         cin >> a >> b;
//         position.push_back({a,b});

//         foo = sortVector(v, a, b);
//     }

//     for (int pIndex = 0; pIndex < m; pIndex++)
//     {
//         for (int pInnerIndex = 0; pInnerIndex < m; pInnerIndex++)
//         {
//             if(sortVector(v, position[pInnerIndex].first, position[pInnerIndex].second))
//                 break;
//         }
//     }

//     for(auto k : v)
//     {
//         cout << k << " ";
//     }
// }

// bool sortVector(vector<int> &v, int a, int b)
// {
//     int aIndex = find(v.begin(), v.end(), a) - v.begin();
//     int bIndex = find(v.begin(), v.end(), b) - v.begin();
//     bool check = false;

//     if(aIndex > bIndex)
//     {
//         aIndex--;
//         v.erase(v.begin()+bIndex);
//         for(int i = aIndex + 1; i < v.size(); i++)
//         {
//             if(v[i] > b)
//             {
//                 v.insert(v.begin() + i, b);
//                 check = true;
//                 break;
//             }
//         }
//         if(!check)
//         {
//             v.insert(v.begin() + aIndex + 1, b);
//         }
//         return true;
//     }
//     return false;
// }

// ################################################################################
// BFS

// vector<pair<int, int>> condition;
// bool compare(vector<int> a, vector<int> b);
// void bfs(vector<vector<int>> &p, int idx, int n);

// int main()
// {
//     fastcpp;
//     int n = 0;
//     int m = 0;
//     int a = 0;
//     int b = 0;
    
//     vector<vector<int>> p;

//     cin >> n >> m;

//     for(int index = 0; index < n; index++)
//     {
//         cin >> a >> b;
//         condition.push_back({b-1,a-1});
//     }
    
//     for(int index = 0; index < n; index++)
//     {
//         if(p.empty())
//             bfs(p, index, n);
//     }

//     for(auto k : p[0])
//     {
//         cout << k+1 <<" ";
//     }
// }

// // condition = [1,3], [2,4]
// // front = [1]
// // idx = 2, 3, 4
// bool Hascondition(vector<int> front, int idx)
// {
//     for(int fIndex = 0; fIndex < front.size(); fIndex++)
//     {
//         for(int index = 0; index < condition.size(); index++)
//         {
//             if ( front[fIndex] == condition[index].first && idx == condition[index].second)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool HasSecondQ(vector<int> v, int idx)
// {
//     for(int index = 0; index < v.size(); index++)
//     {
//         if(front == idx)
//             return true;
//     }
//     return false;
// }

// void bfs(vector<vector<int>> &p, int idx, int n)
// {
//     pair<int, vector<int>> front;
//     vector<pair<int, vector<int>>> q;
//     vector<int> possible;

//     q.push_back({0,{idx}});

//     while(!q.empty())
//     {
//         front = q.front();
//         q.erase(q.begin());

//         if(front.first == n-1)
//         {
//             p.push_back(front.second);
//         }

//         for(int index = 0; index < n; index++)
//         {
//             if (!HasSecondQ(front.second, index))
//             {
//                 if( front.first < n-1)
//                 {
//                     if(Hascondition(front.second, index))
//                     {
//                         vector<int> tmp;
//                         tmp = front.second;
//                         tmp.push_back(index);
//                         q.push_back({front.first+1, tmp});
//                     }
//                 }
//             }
//         }
//     }
// }

