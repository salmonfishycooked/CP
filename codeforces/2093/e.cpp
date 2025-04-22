#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        std::vector<bool> vis(2e5);
        auto check = [&](int v) -> bool {
            int cnt = 0;
            for (int i = 0; i < n; ) {
                int j = i, num = 0;
                for (; j < n; j++) {
                    if (a[j] >= 2e5) { continue; }
                    vis[a[j]] = true;
                    while (num < v && vis[num]) { num += 1; }
                    if (num >= v) {
                        cnt += 1;
                        break;
                    }
                }
                for (; i < n && i <= j; i++) {
                    if (a[i] >= 2e5) { continue; }
                    vis[a[i]] = false;
                }
                if (cnt >= k) { break; }
            }

            return cnt >= k;
        };

        int l = 0, r = 2e5 + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (check(mid)) { l = mid; }
            else { r = mid; }
        }

        std::cout << l << '\n';
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
