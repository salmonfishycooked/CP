#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 power(i64 a, i64 x) {
    i64 res = 1;
    for (; x; x >>= 1) {
        if (x & 1) { res = res * a % MOD; }
        a = a * a % MOD;
    }

    return res;
}

class Solution {
public:
    std::vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

    void solve() {
        i64 n, m, k;
        std::cin >> n >> m >> k;

        int remainEdgeCnt = 2 * m + 2 * n - 8;
        std::map<std::pair<int, int>, int> edges;
        for (int i = 0, x, y, c; i < k; i++) {
            std::cin >> x >> y >> c;
            if ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m)) { continue; }
            if (x == 1 || x == n || y == 1 || y == m) {
                edges[{x, y}] = c;
                remainEdgeCnt -= 1;
            }
        }

        if (remainEdgeCnt) {
            std::cout << power(2, n * m - k - 1) << '\n';
            return;
        }

        int cnt = 0;
        auto add = [&](int x, int y) -> void {
            int myColor = edges[{x, y}];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx <= 0 || nx > n || ny <= 0 || ny > m) { continue; }

                int neighborColor = 1;
                auto it = edges.find({nx, ny});
                if (it == edges.end()) { neighborColor = 0; }
                cnt += neighborColor ^ myColor;
            }
        };

        for (int i = 2; i < m; i++) { add(1, i); }
        for (int i = 2; i < m; i++) { add(n, i); }
        for (int i = 2; i < n; i++) { add(i, 1); }
        for (int i = 2; i < n; i++) { add(i, m); }

        i64 ans = 0;
        if (cnt % 2 == 0) { ans = power(2, n * m - k); }

        std::cout << ans << '\n';
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
