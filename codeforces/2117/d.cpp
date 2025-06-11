#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        int y = (2 * a[0] - a[1]) / (n + 1), x = a[0] - n * y;
        if (2 * a[0] - a[1] < 0 || (2 * a[0] - a[1]) % (n + 1) != 0 || x < 0) {
            std::cout << "NO" << '\n';
            return;
        }

        for (int i = 2; i < n; i++) {
            if (a[i] != (i + 1) * x + (n - i) * y) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        std::cout << "YES" << '\n';
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
