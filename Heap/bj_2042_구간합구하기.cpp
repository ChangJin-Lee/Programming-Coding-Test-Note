#include <iostream>
#include <vector>
#include <cmath>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n, m, k;
vector<long long> v;
vector<long long> tree;

// 세그먼트 트리 초기화
long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = v[start];
    } else {
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    }
}

// 구간 합 구하기
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

// 특정 인덱스 값 변경
void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) {
        return;
    }
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    fastcpp;

    cin >> n >> m >> k;

    v.resize(n + 1);
    tree.resize(4 * n);

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m + k; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            long long diff = c - v[b];
            v[b] = c;
            update(1, 1, n, b, diff);
        } else {
            int b, c;
            cin >> b >> c;
            cout << sum(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}
