#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int cnt[3] = {};

void divide(vector<vector<int>> &v, int row, int col, int len){
    int zeroCnt = 0;
    int oneCnt = 0;
    int size = 0;
    for(int index = row; index < row + len; index++){
        for(int innerIndex = col; innerIndex < col + len; innerIndex++){
            if(v[index][innerIndex] == 0){
                zeroCnt++;
            }else if(v[index][innerIndex] == 1){
                oneCnt++;
            }else{
                continue;
            }
        }
    }

    if(zeroCnt == 0 && oneCnt == 0){
        cnt[0]++;
    }else if(zeroCnt == len*len){
        cnt[1]++;
    }else if(oneCnt == len*len){
        cnt[2]++;
    }else{
        for(int index = 0; index < 3; index++)
        {
            for(int innerIndex = 0; innerIndex < 3; innerIndex++)
            {
                size = len / 3;
                divide(v, row + size * index, col + size * innerIndex, size);
            }
        }
    }

    return;
}

int main(){
    fastcpp;
    vector<vector<int>> v;
    vector<int> tmp;
    int input = 0;
    int n = 0;

    cin >> n;

    for(int index = 0; index < n; index++){
        for(int innerIndex = 0; innerIndex < n; innerIndex++){
            cin >> input;
            tmp.push_back(input);
        }
        v.push_back(tmp);
        tmp.clear();
    }

    divide(v, 0, 0, n);

    for(int index = 0; index < 3; index++){
        cout << cnt[index] << "\n";
    }

    return 0;
}