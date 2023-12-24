#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

void calculateClock(int& h, int& m){
    if (m >= 45) {
        m -= 45;
    } else {
        m += 15;
        if (h == 0 ){
            h = 23;
        } else {
            h -= 1;
        }
    }
}

int main() {
    fastcpp;
    int h, m;
    
    cin >> h >> m;
    calculateClock(h,m);
    cout << h << " " << m << endl;
}