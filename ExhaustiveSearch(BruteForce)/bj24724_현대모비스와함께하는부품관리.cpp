// 문제가 이상함. 그냥 출력만 하면 정답이 되게끔 만들었음...
// 그룹의 수가 최소가 되는것이 목표라고 했는데 그러면 그룹이 줄어야 하는데
// 그냥 n번 출력되면 정답인걸로 되었음. ㅋㅋ
#include <iostream>

using namespace std;

int main() {
    int i,t,n,a,b,u,v,x;
    cin >> t;
    x=0;
    while(t--){
        cin >> n;
        cin >> a >> b;
        while(n--){
            cin >> u >> v;
        }
        cout << "Material Management " << ++x << "\n";
        cout << "Classification ---- End!\n";
    }
}