#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n;
    vector<bool> v(250000,false);
    vector<int> primes;

    for(int i = 2; i < v.size(); i++)
    {
        if(!v[i])
        {
            primes.push_back(i);
            v[i] = true;
            for(int j = i; j < v.size(); j+=i)
            {
                v[j] = true;
            }
        }
    }

    while(cin >> n)
    {
        int answer = 0;
        if( n == 0)
            break;

        for(auto prime : primes)
        {
            if(n < prime && prime <= 2*n)
            {
                answer++;
            }
        }

        cout << answer << "\n";
    }
}