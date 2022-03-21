#include <iostream>

// it is namespace
using namespace std;

int main() {
    int i, v, n,cnt, a[101];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> v;
    cnt = 0;
    for(i=0;i<n;i++)
        if(a[i] == v)
            cnt++;
    cout << cnt;
}