#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;  // input
    int answer = 0;
    cin >> n;   
    vector<int> a(n), b(n);

    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    for (int i=0; i<n; i++){
        answer += a[i] * b[i];
    }
    cout << answer << endl;
}