// 문제가 길어서 어려워 보였지만 잘 생각해보면 간단한 문제였다
//처음에는 트리를 구현해야 하나... bfs, dfs 문제인줄 알았는데
//곰곰이 생각해보니까 그냥 2^n을 구하는 문제였다. 매우 간단했음.
#include <iostream>
using namespace std;

int main() {
    int i,n,k;
    cin >> n;
    k=1;
    for(i=0;i<n;i++) k*=2;
    cout << k;
}