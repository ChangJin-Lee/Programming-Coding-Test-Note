// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 조합을 구하는 재귀 함수
// void findCombinations(vector<int>& arr, int index, int k, int n, vector<int>& combination, int& count) {
//     if (k == 0) {
//         // 3개의 원소를 선택한 경우
//         int sum = 0;
//         for (int num : combination) {
//             sum += num;
//         }
//         if (sum <= n) {
//             count++;
//         }
//         return;
//     }

//     for (int i = index; i < arr.size(); i++) {
//         combination.push_back(arr[i]);
//         findCombinations(arr, i + 1, k - 1, n, combination, count);
//         combination.pop_back();
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     int k = 3; // 3개의 원소를 선택
//     vector<int> arr = {1, 2, 3, 4, 5}; // 배열 예시

//     int count = 0;
//     vector<int> combination;

//     findCombinations(arr, 0, k, n, combination, count);

//     cout << "가능한 조합의 수: " << count << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k = 3; // 3개의 원소를 선택
    vector<int> arr = {1, 2, 3, 4, 5, 6}; // 배열 예시

    int count = 0;
    
    // 배열을 정렬
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 2; i++) {
        int left = i + 1;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum <= n) {
                count += (right - left); // 이 부분 배열에서 만족하는 값들의 수를 더합니다.
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "가능한 조합의 수: " << count << endl;

    return 0;
}
