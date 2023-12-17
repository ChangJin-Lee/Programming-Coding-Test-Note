#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// 1. >> 연산자는 stream으로 부터 값을 읽어서 타겟 변수(cin)에 값을 반환한다.

// 2. 이 때 stream에서 읽은 값이 타겟 변수의 type이 아니라면, stream은 invalid 상태로 mark된다.

// 3. >> 연산자가 stream의 참조값(reference)을 cin에 반환하면, cin은 자신이 상속하는 istream 클래스의 explicit operator bool()로 인해 valid 상태의 stream은 true로, invalid 상태의 stream은 false로 변환하여 반환한다.

int main()
{
    fastcpp;
    int a, b;
    while(cin >> a >> b){
        cout << a+b << "\n";
    }
}