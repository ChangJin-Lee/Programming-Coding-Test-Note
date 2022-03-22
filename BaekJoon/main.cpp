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
<<<<<<< HEAD
    string x,y;
    cin >> x >> y;
    cout << rev(to_string(rev(x) + rev(y)));
=======
    int n[3],i;
    for(i=0;i<3;i++)
        cin >> n[i];
    sort(n,n+3);
    for(i=0;i<3;i++) cout << n[i] <<" ";
>>>>>>> parent of 9b29f5d (bj5543_상근날드.cpp)
}
