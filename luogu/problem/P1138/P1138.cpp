#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        std::vector<bool> vis(30000);
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            vis[v] = true;
        }

        for (int i = 1; i < 30000; i++) {
            if (vis[i]) {
                k -= 1;
                if (k == 0) {
                    std::cout << i;
                    return;
                }
            }
        }

        std::cout << "NO RESULT" << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
