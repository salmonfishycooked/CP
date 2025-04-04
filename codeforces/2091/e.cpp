#include <bits/stdc++.h>

using i64 = long long;

class EuPrime {
public:
    std::vector<int> prime;

    void cal(int n) {
        prime.resize(0);

        std::vector<bool> vis(n + 1);
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) { prime.push_back(i); }
            for (auto num : prime) {
                int v = i * num;
                if (v > n) { break; }
                vis[i * num] = true;
                if (i % num == 0) { break; }
            }
        }
    }
};

class Solution {
public:
    EuPrime eu;

    Solution() { eu.cal(1e7); }

    void solve() {
        int n;
        std::cin >> n;

        auto find = [&](i64 v) -> int {
            int l = -1, r = eu.prime.size();
            while (l + 1 != r) {
                int mid = (l + r) >> 1;
                if (v * eu.prime[mid] <= n) { l = mid; }
                else { r = mid; }
            }

            return l;
        };

        i64 ans = 0;
        for (int i = 1; i <= n; i++) { ans += find(i) + 1; }

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
