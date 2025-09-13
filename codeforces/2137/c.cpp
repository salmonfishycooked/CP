#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        i64 a, b;
        std::cin >> a >> b;

        i64 ans = -1;
        if (a % 2 && b % 2) { ans = a * b + 1; }
        if (a % 2 == 0 && b % 2 == 0 || a % 2 && b % 4 == 0) { ans = a * b / 2 + 2; }

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
