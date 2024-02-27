#include <iostream>
#include <vector>
#include <string>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int t,n;
    string p, input;

    cin >> t;

    while(t--)
    {
        cin >> p >> n >> input;
        
        int idx = 0;
        int cur = 0;
        bool check = false;
        vector<int> v(n,0);
        string buffer = "";
        int left = 0;
        int right = n;


        if(input != "[]")
        {
            for(int i = 1; i < input.size(); i++)
            {
                if(input[i] == ',' || input[i] == ']')
                {
                    v[idx++] = stoi(buffer);
                    buffer = "";
                }
                else
                {
                    buffer += input[i];
                }
            }
        }

        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] == 'R')
            {
                if(cur == left)
                    cur = right;
                else
                    cur = left;
            }
            else
            {
                if(left >= right)
                {
                    check = true;
                    cout << "error";
                    break;
                }
                else
                {
                    if(cur == left)
                    {
                        cur++;
                        left++;
                    }
                    else
                    {
                        cur--;
                        right--;
                    }
                }
            }
        }

        if(!check)
        {
            cout << "[";
            if(cur == left)
            {
                for(int i = left; i < right; i++)
                {
                    cout << v[i];
                    if(i != right-1)
                        cout << ",";
                }
            }
            else
            {
                for(int i = cur - 1; i >= left; i--)
                {
                    cout << v[i];
                    if(i != left)
                        cout << ",";
                }
            }
            cout << "]";
        }

        cout << "\n";
    }
}