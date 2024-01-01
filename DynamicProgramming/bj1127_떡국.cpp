#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main(){
    int n,k;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> vector[i][j];
        }
    }
    
    for( auto k : arr){
        cout << k;
    }
}