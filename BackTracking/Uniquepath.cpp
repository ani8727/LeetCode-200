//  980. Unique Paths III

#include <iostream>
#include <vector>
using namespace std;

int m, n, totalStep;

int obstacle(const vector<vector<int>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == -1) count++;
        }
    }
    return count;
}

int find(vector<vector<int>>& grid, int i, int j, int step) {
    // Boundaries or obstacle → stop
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
        return 0;

    // If reached destination
    if (grid[i][j] == 2) {
        return (step == totalStep) ? 1 : 0;
    }

    // Mark visited
    int temp = grid[i][j];
    grid[i][j] = -1;
    int count = 0;

    for (auto dir : directions) {
        count += find(grid, i + dir.first, j + dir.second, step + 1);
    }

    // Backtrack
    grid[i][j] = temp;
    return count;
}

int path(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int obst = obstacle(grid);
    totalStep = (m * n) - obst;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                ans = find(grid, i, j, 1); // start step = 1
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    cout << path(grid) << endl;  // Output should be 2

    return 0;
}
