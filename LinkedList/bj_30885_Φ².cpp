#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n, input;
    int answer = 0;
    pair<int,int> front, front2;
    vector<pair<int, int>> v;
    vector<pair<int,int>> after;

    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> input;
        answer += input;
        v.push_back({i, input});
    }

    if ( n != 1 )
    {
        after.push_back(v.front());
        v.erase(v.begin());


        while(!v.empty())
        {

            cout << "v\n";
            for(auto k : v)
            {
                cout << k.first << " " << k.second << "\n";
            }

            cout << "after\n";

            for(auto k : after)
            {
                cout << k.first << " " << k.second << "\n";
            }
            cout << "---\n";

            front = v.front();
            v.erase(v.begin());

            if(v.empty())
            {
                if(after.back().second <= front.second)
                {
                    after.back().first = front.first;
                    after.back().second += front.second;
                }
                else
                {
                    after.push_back(front);
                }
            }
            else
            {
                front2 = v.front();
                v.erase(v.begin());
                
                if(after.back().second <= front.second && front.second >= front2.second)
                {
                    after.back().first = front.first;
                    after.back().second += front.second + front2.second;
                }
                else if (after.back().second <= front.second && front.second < front2.second)
                {
                    after.back().first = front.first;
                    after.back().second += front.second;
                    after.push_back(front2);
                }
                else if (after.back().second > front.second && front.second >= front2.second)
                {
                    after.push_back({front.first, front.second + front2.second});
                }
                else
                {
                    after.push_back(front);
                    v.insert(v.begin(), front2);
                }
            }

            if(v.empty())
            {
                if(after.size() == 1)
                    break;
                for(auto k : after)
                {
                    v.push_back(k);
                }
                after.clear();
                after.push_back(v.front());
                v.erase(v.begin());
            }
        }
    }

            cout << "v\n";
            for(auto k : v)
            {
                cout << k.first << " " << k.second << "\n";
            }

            cout << "after\n";

            for(auto k : after)
            {
                cout << k.first << " " << k.second << "\n";
            }
            cout << "---\n";

    cout << answer << "\n" << after.front().first + 1;
}





// int main()
// {
//     fastcpp;
//     int n, input;
//     vector<pair<int, int>> v;

//     cin >> n;

//     for(int i = 0; i < n; i ++)
//     {
//         cin >> input;
//         v.push_back({i, input});
//     }


//     while(v.size() != 1)
//     {
//         int size = v.size();

//         for(int i = 0; i < size; i++)
//         {
//             if(i != 0 && i != size - 1)
//             {
//                 if( v[i-1].second <= v[i].second )
//                 {
//                     v[i].second += v[i-1].second;
//                     v.erase(v.begin() + i - 1);
//                     i--;
//                 }
//                 if( v[i+1].second <= v[i].second)
//                 {
//                     v[i].second += v[i+1].second;
//                     v.erase(v.begin() + i + 1);
//                 }
//             }
//             else if ( i == 0)
//             {
//                 if( v[i+1].second <= v[i].second)
//                 {
//                     v[i].second += v[i+1].second;
//                     v.erase(v.begin() + i+1);
//                 }
//             }
//             else if ( i == size - 1)
//             {
//                 if( v[i-1].second <= v[i].second )
//                 {
//                     v[i].second += v[i-1].second;
//                     v.erase(v.begin() + i - 1);
//                 }
//             }

//             size = v.size();
//         }
//     }

//     cout << v.front().second << "\n" << v.front().first + 1;
// }

