#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i,j,sum=0,t,dwarfs[9];
    for(i=0;i<9;i++) {
        cin >> t;
        dwarfs[i] = t;
        sum+=t;
    }
    sort(dwarfs,dwarfs+9);
    for(i=0;i<9;i++)
        for(j=i+1;j<9;j++)
            if(sum-dwarfs[i]-dwarfs[j] == 100){
                dwarfs[i] = -1;
                dwarfs[j] = -1;
                break;
            }
    for(i=0;i<9;i++)
        if(dwarfs[i] != -1)
            cout << dwarfs[i] << "\n";

}
