#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int to = INT_MIN, flag = 1;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (a[nx][ny] >= a[i][j]) {
                        flag = 0;
                        break;
                    }
                    to = std::max(to, a[nx][ny]);
                }
            }
            if (flag) {
                a[i][j] = to;
            }
        }
    }

    for (auto &row : a) {
        for (auto e : row) {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
