#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    int total = 0;
    std::vector<bool> col(n), lTr(2 * n), rTl(2 * n);
    std::vector<std::vector<int>> ans;
    std::vector<int> cur;

    auto check = [&](int x, int y) -> bool {
        if (col[y] || lTr[x - y + n] || rTl[x + y]) {
            return false;
        }

        return true;
    };

    auto dfs = [&](auto self, int i) -> void {
        if (i == n) {
            total += 1;
            if (ans.size() < 3) {
                ans.push_back(cur);
            }
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!check(i, j)) { continue; }
            col[j] = true;
            lTr[i - j + n] = true;
            rTl[i + j] = true;
            if (ans.size() < 3) {
                cur.push_back(j + 1);
            }
            self(self, i + 1);
            if (ans.size() < 3) {
                cur.pop_back();
            }
            col[j] = false;
            lTr[i - j + n] = false;
            rTl[i + j] = false;
        }
    };
    dfs(dfs, 0);

    std::sort(ans.begin(), ans.end());
    for (auto nums : ans) {
        for (auto num : nums) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    std::cout << total << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
