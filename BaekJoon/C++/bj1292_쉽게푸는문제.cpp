#include <iostream>

// it is namespace
using namespace std;

int main() {
    int arr[500501];
    int a,b,i,s;
    for(i=1,s=1;i<500501;i++){
        arr[i] = s;
        if(i==(s*(s+1))/2) s++;
    }
    cin >> a >> b;
    s=0;
    for(i =a ; i<=b; i++){
        s += arr[i];
    }
    cout << s;
}