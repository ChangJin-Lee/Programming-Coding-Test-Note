// 문자열을 입력받고 string에 존재하는 erase 함수를 사용해보았다.
// 근데 생각해보면 erase 함수가 문자열을 모두 조회하고 삭제하는 행동까지 하므로 시간 복잡도에서 매우 불리하다.
// 다른 사람의 코드를 보니, char형 배열을 적당한 크기로 선언한 후 문자열을 char형 배열에 넣고 그냥 조회만 하면서
// 주어진 조건에 맞게 출력 하게끔 했다. 그게 메모리 크기에도 좋은거 같다.
// 즉 굳이 해당하는 타겟 문자를 문자열에서 삭제해버릴 필요까지는 없다는 말이다.

#include <iostream>
#include <string>

// it is namespace
using namespace std;

int main() {
    int t,target;
    string strings;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> target >> strings;
        strings.erase(target-1, 1); // pos 부터 몇개 만큼 삭제할 것 인지 적어야함. 아니면 pos 뒤로 다 삭제됨.
        cout << strings << "\n";
    }
}