//n,m 길이를 비교해야함. 난 n문자열의 길이랑 m이랑 비교했는데,
//그렇게 하면 안되고 n문자열의 길이 * n 이랑 m의 크기랑 비교해야함.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n,m,i,k,z,j,minval;
    string ns;
    cin >> n >> m;
    ns = to_string(n);
    k = ns.length();
    z=k*n;
    minval = (z>=m)? m:z;
    for(i=0;i<minval/k;i++){
        cout << ns;
    }
    for(i=0;i<minval%k;i++){
        cout << ns[i];
    }

}
