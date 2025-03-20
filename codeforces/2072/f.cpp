#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    std::vector<int> has2 = std::vector<int>(1e6);

    Solution() {
        auto calc = [&](int v) -> int {
            i64 cur = 2, cnt = 0;
            while (v % cur == 0) {
                cur *= 2;
                cnt += 1;
            }

            return cnt;
        };

        for (int i = 2; i < 1e6; i++) {
            has2[i] = has2[i - 1] + calc(i);
        }
    }

    void solve() {
        int n, k;
        std::cin >> n >> k;

        n -= 1;
        for (int i = 0; i <= n; i++) {
            std::cout << (has2[n] > has2[n - i] + has2[i] ? 0 : k) << ' ';
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
