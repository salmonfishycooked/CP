#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<std::pair<i64, int>> a(n);
        for (i64 i = 0, v; i < n; i++) {
            std::cin >> v;
            a[i] = {v + i, i};
        }

        auto find = [&](i64 v) -> int {
            int l = -1, r = n;
            while (l + 1 != r) {
                int mid = (l + r) >> 1;
                if (a[mid].first >= v) {
                    r = mid;
                } else {
                    l = mid;
                }
            }

            if (r != n && a[r].first > v) { return n; }

            return r;
        };

        std::sort(a.begin(), a.end());

        std::vector<i64> f(n, -1);
        auto dfs = [&](auto self, int i) -> i64 {
            if (i >= n) { return 0; }

            if (f[i] != -1) { return f[i]; }

            i64 res = 0, curLen = a[i].first;
            for (int j = i; j < n && a[j].first == curLen; j++) {
                if (a[j].second == 0) { continue; }
                int next = find(curLen + a[j].second);
                res = std::max(res, self(self, next) + a[j].second);
            }

            return f[i] = res;
        };

        i64 ans = 0;
        for (int i = find(n); i < n && a[i].first == n; i++) {
            if (a[i].second == 0) { continue; }
            int next = find(a[i].first + a[i].second);
            ans = std::max(ans, dfs(dfs, next) + a[i].second);
        }
        ans += n;

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) {
        s.solve();
    }

    return 0;
}
