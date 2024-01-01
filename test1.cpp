#include <iostream>
#include <vector>
#include <algorithm>

bool isOverlap(const std::vector<int>& seg1, const std::vector<int>& seg2) {
    return seg1[1] >= seg2[0] && seg2[1] >= seg1[0];
}

std::vector<std::vector<int>> mergeSegments(const std::vector<std::vector<int>>& segments) {
    if (segments.empty()) {
        return segments;
    }

    std::vector<std::vector<int>> mergedSegments;
    std::vector<int> current = segments[0];

    for (int i = 1; i < segments.size(); i++) {
        if (isOverlap(current, segments[i])) {
            current[0] = std::min(current[0], segments[i][0]);
            current[1] = std::max(current[1], segments[i][1]);
        } else {
            mergedSegments.push_back(current);
            current = segments[i];
        }
    }

    mergedSegments.push_back(current);

    return mergedSegments;
}

int main() {
    // std::vector<std::vector<int>> segments = {{6, 7}, {6, 6}, {1, 3}, {2, 2}, {1, 2}};
    std::vector<std::vector<int>> segments = {{6, 9}, {2, 3}, {9, 11}, {1, 5}, {14, 18}};

    // 0번 index를 기준으로 정렬
    std::sort(segments.begin(), segments.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> mergedSegments = mergeSegments(segments);

    std::cout << "Merged Segments: ";
    for (const std::vector<int>& segment : mergedSegments) {
        std::cout << "[" << segment[0] << ", " << segment[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
