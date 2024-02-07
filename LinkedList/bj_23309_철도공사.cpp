#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n,m,i,j,input;
    string buildCommand;
    vector<int> left;

    cin >> n >> m;

    for(int h = 0; h < n; h++)
    {
        cin >> input;
        left.push_back(input);
    }

    // for( auto k : left)
    // {
    //     cout << k << "\n";
    // }

    while(m--)
    {
        cin >> buildCommand;

        // cout << "========== start \n" << buildCommand << "\n";
        // cout << "left======= \n";
        // for( auto k : left)
        // {
        //     cout << k << "\n";
        // }
        // cout << "==============\n";

        if(buildCommand == "BN")
        {
            cin >> i >> j;
            auto cur = find(left.begin(), left.end(), i);
            if(cur != prev(left.end()))
            {
                cout << (*next(cur));
                left.insert(next(cur),j);
            }
            else
            {
                cout <<(*(left.begin()));
                left.push_back(j);
            }
        }
        else if(buildCommand == "BP")
        {
            cin >> i >> j;
            auto cur = find(left.begin(), left.end(), i);
            if(cur != left.begin())
            {
                cout << (*prev(cur));
                left.insert(cur,j);
            }
            else
            {
                cout <<(*(left.end()));
                left.push_back(j);
            }
        }
        else if(buildCommand == "CN")
        {
            cin >> i;
            auto cur = find(left.begin(), left.end(), i);
            if(cur != prev(left.end()))
            {
                cout << (*next(cur));
                left.erase(next(cur));
            }
            else
            {
                cout <<(*(left.begin()));
                left.erase(left.begin());
            }
        }
        else if(buildCommand == "CP")
        {
            cin >> i;
            auto cur = find(left.begin(), left.end(), i);
            if(cur != left.begin())
            {
                cout << (*prev(cur));
                left.erase(prev(cur));
            }
            else
            {
                cout <<(*(prev(left.end())));
                left.erase(prev(left.end()));
            }
        }
        cout  << "\n";
    }
}


// #include <iostream>
// #include <queue>
// #include <string>

// #define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

// using namespace std;

// int main()
// {
//     int n,m,i,j,input;
//     string buildCommand;
//     deque<int> left, right;

//     cin >> n >> m;

//     for(int i = 0; i < n; i++)
//     {
//         cin >> input;
//         left.push_back(input);
//     }

//     // for( auto k : left)
//     // {
//     //     cout << k << "\n";
//     // }

//     while(m--)
//     {
//         cin >> buildCommand;

//         // cout << "========== start \n" << buildCommand << "\n";
//         // cout << "left======= \n";
//         // for( auto k : left)
//         // {
//         //     cout << k << "\n";
//         // }
//         // cout << "right======= \n";
//         // for( auto k : right)
//         // {
//         //     cout << k << "\n";
//         // }
//         // cout << "==============\n";

//         if(buildCommand == "BN")
//         {
//             cin >> i >> j;
//             int cur = left.back();
//             while(cur != i)
//             {
//                 left.pop_back();
//                 right.push_back(cur);
//                 cur = left.back();
//             }
//             if(right.empty())
//                 cout << left.front() << "\n";
//             else
//                 cout << right.back() << "\n";
//             left.push_back(j);
//         }
//         else if(buildCommand == "BP")
//         {
//             cin >> i >> j;
//             int cur = left.back();
//             while(cur != i)
//             {
//                 left.pop_back();
//                 right.push_back(cur);
//                 cur = left.back();
//             }
//             if(left.size() == 1)
//             {
//                 cout << right.front() << "\n";
//                 right.push_front(j);
//             }
//             else
//             {
//                 cout << left[left.size()-2] << "\n";
//                 left.insert(left.end()-1, j);
//             }
//         }
//         else if(buildCommand == "CN")
//         {
//             cin >> i;
//             if(left.size() >= 2)
//             {
//                 int cur = left.back();
//                 while(cur != i)
//                 {
//                     left.pop_back();
//                     right.push_back(cur);
//                     cur = left.back();
//                 }
//                 cout << right.back() << "\n";
//                 right.pop_back();
//             }
//         }
//         else if(buildCommand == "CP")
//         {
//             cin >> i;
//             if(left.size() >= 2)
//             {
//                 int cur = left.back();
//                 while(cur != i)
//                 {
//                     left.pop_back();
//                     right.push_back(cur);
//                     cur = left.back();
//                 }
//                 if(left.size() == 1)
//                 {
//                     cout << right.front() << "\n";
//                     right.pop_front();
//                 }
//                 else
//                 {
//                     cout << left[left.size()-2] << "\n";
//                     left.erase(left.end()-2);
//                 }
                
//             }
//         }

//         while(!right.empty())
//         {
//             left.push_back(right.back());
//             right.pop_back();
//         }
//     }
// }