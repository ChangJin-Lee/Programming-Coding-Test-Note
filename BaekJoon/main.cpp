#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n[3],i;
    for(i=0;i<3;i++)
        cin >> n[i];
    sort(n,n+3);
    for(i=0;i<3;i++) cout << n[i] <<" ";
}
