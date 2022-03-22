#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n,m,i,k;
    cin >> n >> m;
    if(n>m) k = m;
    else k=n;
    for(i=0;i<k;i++)
        cout << n;
}
