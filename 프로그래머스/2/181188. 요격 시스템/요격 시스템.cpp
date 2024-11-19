#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 0;
    int last_end = -1;

    for (const auto& target : targets) {
        if (target[0] >= last_end) {
            count++;
            last_end = target[1];
        }
    }

    return count;
}