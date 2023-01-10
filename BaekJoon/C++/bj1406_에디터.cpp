#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> v;
    string st;
    cin >> st;

    for(auto k : st) v.push_back(k);
    int idx;
    vector<char>::iterator it =  v.end();;
    cin >> idx;
    while(idx--){
        char cmd;
        cin >> cmd;
        if(cmd=='P'){
            char addcmd;
            cin >> addcmd;
            it = v.insert(it, addcmd)+1;
        }
        else if(cmd=='L'){
            if(it != v.begin()) it--;
        }
        else if(cmd=='D'){
            if(it != v.end()) it++;
        }
        else{
            if(it != v.begin()){
                it--;
                it = v.erase(it);
            }
        }
    }
    for(auto k : v) cout << k;
}