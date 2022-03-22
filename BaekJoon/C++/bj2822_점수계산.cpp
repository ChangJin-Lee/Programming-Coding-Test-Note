//배열의 정렬은 이미 algorithm 헤더에 포함되어 있다. 가져다 쓰면 됨.
//필요한 배열은 그냥 선언해서 쓰자.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[151]={0},i,sum=0,t,points[8],result[5];
    for(i=0;i<8;i++){
        cin >> t;
        arr[t] = i+1;
        points[i] = t;
    }
    sort(points,points+8);
    for(i=3;i<8;i++) {
        result[i - 3] = arr[points[i]];
        sum+=points[i];
    };
    sort(result,result+5);
    cout << sum << "\n";
    for(i=0;i<5;i++) cout << result[i] << " ";
}
