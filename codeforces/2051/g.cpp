#include <bits/stdc++.h>

using i64 = long long;

int f[20][1 << 20];

class Solution {
public:
    void solve() {
        int n, q;
        std::cin >> n >> q;

        std::vector<std::pair<int, char>> ops(q);
        for (auto &[f, s] : ops) {
            std::cin >> f >> s;
            f -= 1;
        }

        std::vector minDis(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) { continue; }
                int dis = 0, jLen = 1;
                for (auto &[id, op] : ops) {
                    if (id == i && op == '+') { dis += 1; }
                    if (id == j) {
                        if (op == '+') { jLen += 1; }
                        else if (op == '-') {
                            dis -= jLen > 1;
                            jLen = std::max(1, jLen - 1);
                        }
                    }
                    minDis[i][j] = std::max(minDis[i][j], dis);
                }
            }
        }

        std::vector<int> occupied(n, 1);
        for (auto &[id, op] : ops) {
            if (op == '+') { occupied[id] += 1; }
        }

        int allSet = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            for (int j = allSet; j >= 0; j--) {
                f[i][j] = INT_MAX / 2;
            }
        }
        for (int i = 0; i < n; i++) { f[i][allSet] = 0; }
        for (int msk = allSet - 1; msk >= 0; msk--) {
            for (int pre = 0; pre < n; pre++) {
                for (int i = 0; i < n; i++) {
                    if (msk & (1 << i)) { continue; }
                    int dis = minDis[pre][i];
                    int devotion = occupied[i] - occupied[pre] + dis + 1;
                    f[pre][msk] = std::min(f[pre][msk], f[i][msk | (1 << i)] + devotion);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) { ans = std::min(ans, occupied[i] + f[i][1 << i]); }
        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
