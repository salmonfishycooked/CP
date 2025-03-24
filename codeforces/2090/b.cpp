#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::string> grid(n);
        for (int i = 0; i < n; i++) { std::cin >> grid[i]; }

        std::vector flag(n, std::vector<bool>(m));
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < m && grid[i][j] == '1') {
                flag[i][j] = true;
                j += 1;
            }
        }
        for (int j = 0; j < m; j++) {
            int i = 0;
            while (i < n && grid[i][j] == '1') {
                flag[i][j] = true;
                i += 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !flag[i][j]) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }
        }

        std::cout << "YES" << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
