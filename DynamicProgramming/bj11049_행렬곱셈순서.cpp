#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

// 누적합 + dp 문제

using namespace std;

int dp(vector<vector<int>> v, int n, int p){

}

int main(){
    fastcpp;
    int n;
    vector<int> f;
    vector<vector<int>> arr(n, vector<int>(2,0));

    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    f.push_back([0][0] * arr[0][1]);

    
}