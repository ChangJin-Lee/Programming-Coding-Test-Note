#include <iostream>
#include <string>

// it is namespace
using namespace std;

int main() {
    int geton, getoff;
    int passingers = 0;
    int maxval = 0;

    for(int i=0;i<10;i++){  // 10개의 기차역
        cin >> getoff >> geton;
//        cout << getoff << " " << geton << "\n";
        passingers += geton - getoff;
        if(maxval < passingers){
            maxval = passingers;
        }

    }
    cout << maxval;
}