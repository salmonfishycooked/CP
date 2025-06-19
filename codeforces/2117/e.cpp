#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }
        for (int i = 0; i < n; i++) { std::cin >> b[i]; }

        if (a.back() == b.back()) {
            std::cout << n << '\n';
            return;
        }

        int ans = 0;
        std::vector<bool> vis(n + 1);
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || vis[a[i]] || vis[b[i]]) {
                ans = i + 1;
                break;
            }

            vis[a[i + 1]] = vis[b[i + 1]] = true;
        }

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
