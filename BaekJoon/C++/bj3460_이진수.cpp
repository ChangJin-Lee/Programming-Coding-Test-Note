#include <iostream>

// it is namespace
using namespace std;

int main() {
    int t,i,j,input;
    cin >> t;
    for(i=0;i<t;i++){
        cin >> input;
        j=0;
        while(1){
            if(input ==1 ) {
                cout << j << " ";
                break;
            }
            if(input ==0) {
                break;
            }
            if(input%2 == 1){
                cout << j << " ";
            }
            input /= 2;
            j++;
        }
        cout << "\n";
    }
}