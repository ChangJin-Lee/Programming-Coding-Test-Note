#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void Swap(vector<int>& v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    fastcpp;
    int n, m;
    int i,j;
    cin >> n >> m;
    vector<int> v(n,0);
    for (int index=0; index < n; index++){
        v[index] = index+1;
    }
    for (int index=0; index < m; index++){
        cin >> i >> j;
        Swap(v,i-1,j-1);
    }
    for (auto k : v){
        cout << k << " ";
    }
}

