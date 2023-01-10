#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,i,k;
    cin >> n >> m;
    if(n>m) k = m;
    else k=n;
    for(i=0;i<k;i++)
        cout << n;
    vector<int> v(2);
    for(int k : v){
        cout << k;
    }
    for(int k : 5)
        cout << "test";
}
