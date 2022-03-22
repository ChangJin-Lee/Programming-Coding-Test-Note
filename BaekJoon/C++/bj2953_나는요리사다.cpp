//처음에는 배열을 선언해서 쓰려고 했는데 굳이 그럴 필요가 없었다.
//C++를 쓰면서 느낀건데 많은 경우에 원하는 조건으로 조회하는 쪽으로 코딩을 하는 것 같다.

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