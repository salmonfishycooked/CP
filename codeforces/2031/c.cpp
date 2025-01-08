#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) { std::cout << i << ' ' << i << ' '; }
            std::cout << '\n';
            return;
        }

        if (n >= 27) {
            int cur = 3, cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (i == 1 || i == 10 || i == 26) {
                    std::cout << 1 << ' ';
                    continue;
                }
                if (i == 11 || i == 27) {
                    std::cout << 2 << ' ';
                    continue;
                }

                std::cout << cur << ' ';
                cnt += 1;
                if (cnt == 2) {
                    cur += 1;
                    cnt = 0;
                }
            }
            std::cout << '\n';
            return;
        }

        std::cout << "-1" << '\n';
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
