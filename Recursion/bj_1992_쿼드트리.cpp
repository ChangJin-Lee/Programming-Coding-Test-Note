#include <iostream>
#include <vector>
#include <string>
#define fastcpp ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<vector<int> > v;
string answer;

void Recursion(int row, int col, int len){
    bool isSame = true;
    int size = len/2;
    for(int index = row; index < row + len; index++){
        for(int innerIndex = col; innerIndex < col + len; innerIndex++){
            if(v[index][innerIndex] != v[row][col]){
                isSame = false;
                break;
            }
        }
        if(!isSame){
            break;
        }
    }

    if(!isSame){
        answer += "(";
        for(int index = 0; index < 2; index++)
        {
            for(int innerIndex = 0; innerIndex < 2; innerIndex++)
            {
                Recursion(row + size*index, col + size*innerIndex, size);
            }
            
        }
        answer += ")";
    }else{
        answer += v[row][col];
    }

    return;
}

int main(){
    fastcpp;
    int n;
    string input;
    vector<int> tmp;

    cin >> n;

    for(int index = 0; index < n; index++){
        
        cin >> input;
        for(int innerIndex = 0; innerIndex < n; innerIndex++){
            
            tmp.push_back((int)input[innerIndex]);
        }
        v.push_back(tmp);
        tmp.clear();
    }

    Recursion(0, 0, n);

    cout << answer;
}