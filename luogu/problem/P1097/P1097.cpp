#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::map<int, int> cnt;
        for (int i = 0, v; i < n; i++) {
            std::cin >> v;
            cnt[v] += 1;
        }

        for (auto [num, tot] : cnt) {
            std::cout << num << ' ' << tot << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
