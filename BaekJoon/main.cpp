#include <iostream>

// it is namespace
using namespace std;

int main() {
    int i,j,a,sum;
    int maxval,winner;
    maxval = 0;
    for(i=0; i<5; i++) {
        sum = 0;
        for (j=0;j<4;j++){
            cin >> a;
            sum+=a;
        }
        if(maxval < sum) {
            maxval = sum;
            winner = i+1;
        }
    }
    cout << winner << " " << maxval;
}