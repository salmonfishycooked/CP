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
    void solve() {
        int n;
        std::cin >> n;

        EuPrime eu;
        eu.cal(n);

        int p = *std::lower_bound(eu.prime.begin(), eu.prime.end(), n / 3);

        std::vector<bool> vis(n + 1);
        vis[p] = true;
        std::cout << p << ' ';
        for (int times = 1; times <= n / 3 - 2; times++) {
            std::cout << p - times << ' ';
            std::cout << p + times << ' ';
            vis[p - times] = true;
            vis[p + times] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) { std::cout << i << ' '; }
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
