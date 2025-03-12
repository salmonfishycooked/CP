#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, x;
        std::cin >> n >> x;

        int sum = 0;
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            sum += v;
        }

        std::cout << ((sum == n * x) ? "YES" : "NO") << '\n';
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
