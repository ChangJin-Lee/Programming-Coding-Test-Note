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