// #include <iostream>
// #include <vector>

// int findFirstIndexLessThanT(std::vector<int>& arr, int t) {
//     int n = arr.size();
//     int currentIndex = 0;
//     int currentSum = 0;

//     while (currentIndex < n) {
//         // 현재 요소를 1 감소시킴
//         arr[currentIndex] -= 1;

//         // 배열의 모든 요소의 합을 다시 계산
//         currentSum = 0;
//         for (int i = 0; i < n; i++) {
//             if(arr[i] > 0)
//                 currentSum += arr[i];
//         }

//         // 만약 합이 t보다 작아지면 현재 인덱스 반환
//         if (currentSum < t) {
//             return currentIndex;
//         }

//         // 다음 인덱스로 이동
//         currentIndex++;
//     }

//     // t보다 작아지는 경우가 없으면 -1 반환
//     return -1;
// }

// int main() {
//     // std::vector<int> arr = {5, 3, 8, 2};
//     std::vector<int> arr = {4, 8, 7, 1, 2};
//     // int t = 15;
//     int t = 9;

//     int result = findFirstIndexLessThanT(arr, t);

//     if (result != -1) {
//         std::cout << "첫 번째로 합이 " << t << "보다 작아지는 인덱스: " << result << std::endl;
//     } else {
//         std::cout << "해당 조건을 만족하는 경우를 찾지 못했습니다." << std::endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>

// int findFirstIndexLessThanT(std::vector<int>& arr, int t) {
//     int n = arr.size();
//     int currentIndex = 0;
//     int currentSum = 0;

//     while (currentIndex < n) {
//         // 현재 요소를 1 감소시킴
//         arr[currentIndex] -= 1;

//         // 요소가 0보다 작아지면 다시 1 더해줌
//         if (arr[currentIndex] < 0) {
//             arr[currentIndex] += 1;
//         }

//         // 배열의 모든 양의 정수 요소의 합을 계산
//         currentSum = 0;
//         for (int i = 0; i < n; i++) {
//             if (arr[i] > 0) {
//                 currentSum += arr[i];
//             }
//         }

//         // 만약 합이 t보다 작아지면 현재 인덱스 반환
//         if (currentSum < t) {
//             return currentIndex;
//         }

//         // 다음 인덱스로 이동
//         currentIndex++;
//     }

//     // t보다 작아지는 경우가 없으면 -1 반환
//     return -1;
// }

// int main() {
//     // std::vector<int> arr = {5, -2, 3, 8, 2};
//     std::vector<int> arr = {4, 8, 7, 1, 2};
//     // int t = 15;
//     int t = 9;
    
//     int result = findFirstIndexLessThanT(arr, t);

//     if (result != -1) {
//         std::cout << "첫 번째로 합이 " << t << "보다 작아지는 인덱스: " << result << std::endl;
//     } else {
//         std::cout << "해당 조건을 만족하는 경우를 찾지 못했습니다." << std::endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>

int findIndexWithSumLessThanT(std::vector<int>& arr, int t) {
    int n = arr.size();
    int currentIndex = 0;
    int currentSum = 0;

    while (true) {
        // 현재 요소를 1 감소시킴
        arr[currentIndex] -= 1;

        // 요소가 0보다 작아지면 다시 1 더해줌
        if (arr[currentIndex] < 0) {
            arr[currentIndex] += 1;
        }

        // 배열의 모든 양의 정수 요소의 합을 계산
        currentSum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                currentSum += arr[i];
            }
        }
        std::cout << currentSum << std::endl;
        // 만약 합이 t보다 작아지면 현재 인덱스 반환
        if (currentSum < t) {
            return currentIndex;
        }

        // 다음 인덱스로 이동
        currentIndex = (currentIndex + 1) % n;
    }
}

int main() {
    // std::vector<int> arr = {5, -2, 3, 8, 2};
    // int t = 15;
    std::vector<int> arr = {4, 8, 7, 1, 2};
    int t = 9;

    int result = findIndexWithSumLessThanT(arr, t);

    if (result != -1) {
        std::cout << "첫 번째로 합이 " << t << "보다 작아지는 인덱스: " << result << std::endl;
    } else {
        std::cout << "해당 조건을 만족하는 경우를 찾지 못했습니다." << std::endl;
    }

    return 0;
}
