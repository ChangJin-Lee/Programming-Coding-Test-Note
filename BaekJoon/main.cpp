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
