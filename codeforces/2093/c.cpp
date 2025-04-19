#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        auto isPrime = [&](int num) -> bool {
            if (num == 1) { return false; }
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) { return false; }
            }

            return true;
        };

        int ans = k < 3 && ((k == 2 && n == 1) || (k == 1 && isPrime(n)));
        std::cout << (ans ? "YES" : "NO") << '\n';
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
