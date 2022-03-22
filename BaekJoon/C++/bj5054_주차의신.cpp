//마지막에 개행문자를 출력해야 정답으로 인정되더라..
//이상하긴한데 잘 안될때는 마지막에 \n을 출력해보자

#include <iostream>

// it is namespace
using namespace std;

int main() {
    int i,t,n,minval,maxval,tmp;
    cin >> t;
    while(t--) {
        minval=100;
        maxval=0;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp > maxval) maxval = tmp;
            if(tmp < minval) minval = tmp;
        }
        cout << (maxval - minval)*2 << "\n";
    }
}
