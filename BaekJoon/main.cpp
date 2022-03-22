#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int menu[5],i,j,set[6],k=0;
    for(i=0;i<5;i++)
        cin >> menu[i];
    for(i=0;i<3;i++)
        for(j=3;j<5;j++) {
            set[k] = menu[i] + menu[j] - 50;
            k++;
        }
    sort(set,set+6);
    cout << set[0];
}
