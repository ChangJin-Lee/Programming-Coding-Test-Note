#include <iostream>

// it is namespace
using namespace std;

int main() {
    int i,t,n,minval,maxval,tmp;
    cin >> t;
    while(t--) {
        minval=99;
        maxval=0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp > maxval) maxval = tmp;
            if(tmp < minval) minval = tmp;
        }
        cout << (maxval - minval)*2;
    }
}
