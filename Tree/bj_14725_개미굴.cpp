#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

// 개미굴의 각 노드를 나타내는 클래스
class AntHill {
public:
    map<string, AntHill*> children; // 자식 노드를 저장하는 맵

    // 노드에 새로운 경로를 추가하는 함수
    void insert(vector<string>& path, int index) {
        if (index == path.size()) return; // 경로의 끝에 도달했으면 종료
        string next = path[index];
        if (children.find(next) == children.end()) {
            children[next] = new AntHill(); // 다음 노드가 없으면 생성
        }
        children[next]->insert(path, index + 1); // 재귀적으로 다음 노드에 경로 추가
    }

    // 개미굴의 구조를 출력하는 함수
    void print(int depth = 0) {
        for (auto& child : children) {
            cout << string(depth * 2, '-') << child.first << '\n';
            child.second->print(depth + 1); // 재귀적으로 자식 노드 출력
        }
    }
};

int main() {
    fastcpp;
    int N;
    cin >> N;

    AntHill root; // 개미굴의 루트 노드

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<string> path(K);
        for (int j = 0; j < K; j++) {
            cin >> path[j]; // 경로 입력 받기
        }
        root.insert(path, 0); // 루트 노드부터 경로 추가
    }

    root.print(); // 개미굴의 구조 출력
    return 0;
}
