#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int x, y, a;
        std::cin >> x >> y >> a;

        a = a % (x + y);
        if ((double) x >= a + 0.5) {
            std::cout << "NO" << '\n';
            return;
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
