//노트북에서 공부할땐 안보이던게 데탑 큰 화면으로 보이니까 바로 보였음.
//확실히 디스플레이는 큰게 장땡이긴 함.
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i,j,sum=0,t,dwarfs[9];
    bool z = false;
    for(i=0;i<9;i++) {
        cin >> t;
        dwarfs[i] = t;
        sum+=t;
    }
    sort(dwarfs,dwarfs+9);
    for(i=0;i<9;i++) {
        for (j = i + 1; j < 9; j++)
            if (sum - dwarfs[i] - dwarfs[j] == 100) {
                dwarfs[i] = -1;
                dwarfs[j] = -1;
                z = true;
                break;
            }
        if(z) break;
    }
    for(i=0;i<9;i++)
        if(dwarfs[i] != -1)
            cout << dwarfs[i] << "\n";

}

//
// Created by Chang Jin Lee on 2022/03/21.
//

