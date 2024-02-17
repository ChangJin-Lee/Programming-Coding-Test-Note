// 이 문제의 핵심은 이거임
// 예를 들어 6853 페이지를 구한다
// 그러면 6850 - 6853 까지의 숫자
// 다음은 6800 - 6850
// 다음은 6000 - 6800
// 다음은 0 - 6000
// 이 4가지의 모든 수를 구하면 정답임

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, cnt[10] = {}, add = 0;
    cin >> N;

    for(int i=1; N!=0; i*=10) {
        int curr = N%10;
        N /= 10;

        cnt[0] -= i;
        for(int j=0; j<curr; j++) cnt[j] += (N+1)*i;
        cnt[curr] += N*i + 1 + add;
        for(int j=curr+1; j<=9; j++) cnt[j] += N*i;

        add += curr*i;
    }

    for(int i=0; i<=9; i++) cout << cnt[i] << " ";
}