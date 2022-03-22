#include <iostream>
#include <algorithm>

using namespace std;

int main() {
<<<<<<< HEAD
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

=======
    int n[3],i;
    for(i=0;i<3;i++)
        cin >> n[i];
    sort(n,n+3);
    for(i=0;i<3;i++) cout << n[i] <<" ";
>>>>>>> parent of 9b29f5d (bj5543_상근날드.cpp)
}
