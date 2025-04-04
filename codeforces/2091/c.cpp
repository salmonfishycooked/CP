#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        if (n % 2 == 0) {
            std::cout << -1 << '\n';
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (i % 2) { std::cout << i << ' '; }
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) { std::cout << i << ' '; }
        }
        std::cout << '\n';
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
