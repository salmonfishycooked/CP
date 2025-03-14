#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        if (k % 2) {
            for (int i = 1; i < n; i++) { std::cout << n << ' '; }
            std::cout << n - 1 << ' ';
        } else {
            for (int i = 1; i <= n; i++) {
                if (i == n - 1) {
                    std::cout << n << ' ';
                    continue;
                }
                std::cout << n - 1 << ' ';
            }
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
