#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int minimumTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();
    vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Start from (0, 0) at time 0
    pq.emplace(0, 0, 0);
    minTime[0][0] = 0;

    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!pq.empty()) {
        auto [currentTime, x, y] = pq.top();
        pq.pop();

        if (x == n - 1 && y == m - 1) {
            return currentTime;
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int waitTime = max(0, moveTime[nx][ny] - (currentTime + 1));
                int newTime = currentTime + 1 + waitTime;

                if (newTime < minTime[nx][ny]) {
                    minTime[nx][ny] = newTime;
                    pq.emplace(newTime, nx, ny);
                }
            }
        }
    }

    return -1; // Should never reach here
}

int main() {
    vector<vector<int>> moveTime1 = {{0, 4}, {4, 4}};
    cout << "Example 1 Output: " << minimumTimeToReach(moveTime1) << endl;

    vector<vector<int>> moveTime2 = {{0, 0, 0}, {0, 0, 0}};
    cout << "Example 2 Output: " << minimumTimeToReach(moveTime2) << endl;

    vector<vector<int>> moveTime3 = {{0, 1}, {1, 2}};
    cout << "Example 3 Output: " << minimumTimeToReach(moveTime3) << endl;

    return 0;
}