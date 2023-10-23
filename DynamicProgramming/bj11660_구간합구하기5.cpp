#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

// 누적합 + dp 문제

using namespace std;

int main(){
    fastcpp;
    int n, m, x1, y1, x2, y2, answer;
    cin >> n >> m;
    vector<vector<int>> arr(n+2, vector<int>(n+2,0));
    vector<vector<int>> prefix_sum(n+2, vector<int>(n+2,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            prefix_sum[i][j] = arr[i][j] + prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1];
        }
    }

    for(int i=0; i<m ; i++){
        answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        answer = prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
        cout << answer << "\n";
    }
}