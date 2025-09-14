#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        i64 tot = 0;
        std::vector<int> odds;
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            if (num % 2 == 0) {
                tot += num;
            } else {
                odds.push_back(num);
            }
        }

        if (odds.empty()) {
            std::cout << 0 << '\n';
            return;
        }

        std::sort(odds.begin(), odds.end());
        auto cnt = (odds.size() + 1) >> 1;
        tot += std::accumulate(odds.end() - static_cast<long>(cnt), odds.end(), 0LL);

        std::cout << tot << '\n';
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
