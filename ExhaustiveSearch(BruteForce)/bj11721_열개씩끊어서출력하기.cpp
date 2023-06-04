#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int i;
    string n;
    cin >> n;
    for(i=0;i<n.length();i++){
        if(i%10==0 and i!=0) cout << "\n";
        cout << n[i];
    }
}