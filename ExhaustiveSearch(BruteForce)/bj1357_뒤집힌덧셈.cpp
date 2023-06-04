//문자열과 int형 변환에 대한 내용이었다.
//string 헤더파일을 추가해줘야하고,
//stoi -> 이걸로 문자열을 int형으로 바꿀 수 있고,
//to_string -> 이걸로 int형을 문자열로 바꿀 수 있다.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long rev(string x){
    int i;
    string result = "";
    for(i=x.length()-1;i>=0;i--){
        result+=x[i];
    }
    return stoi(result);
}

int main() {
    string x,y;
    cin >> x >> y;
    cout << rev(to_string(rev(x) + rev(y)));
}
