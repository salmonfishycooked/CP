#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        while (std::cin >> n >> m) {
            if (n == 0) { break; }

            std::vector grid(n, std::vector<char>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) { std::cin >> grid[i][j]; }
            }

            std::vector<int> dx = {-1, 0, 1}, dy = {-1, 0, 1};
            auto dfs = [&](auto self, int i, int j) -> void {
                grid[i][j] = '*';
                for (auto deltaX : dx) {
                    for (auto deltaY : dy) {
                        int nx = i + deltaX, ny = j + deltaY;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*') { continue; }
                        self(self, nx, ny);
                    }
                }
            };

            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '@') {
                        ans += 1;
                        dfs(dfs, i, j);
                    }
                }
            }

            std::cout << ans << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
