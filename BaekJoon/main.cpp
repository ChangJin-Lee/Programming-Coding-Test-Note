#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int rev(string x){
    int i;
    string result = "";
    for(i=x.length();i>0;i--){
        result+=x[i];
    }
    return stoi(result);
}

int main() {
    string x,y;
    cin >> x >> y;
    cout << rev(x);
}
