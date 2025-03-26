#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int l, r;
        std::cin >> l >> r;

        int pos = 31 - __builtin_clz(l ^ r);
        int a = l | ((1 << pos) - 1), b = a + 1, c = (a == l ? r : l);
        std::cout << a << ' ' << b << ' ' << c << '\n';
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
