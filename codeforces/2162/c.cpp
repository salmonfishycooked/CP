#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int a, b;
        std::cin >> a >> b;

        if (a == b) {
            std::cout << 0 << '\n';
            return;
        }

        std::vector<int> ba(32), bb(32);
        for (int i = 0; i < 32; ++i) {
            ba[i] = (a >> i) & 1;
            bb[i] = (b >> i) & 1;
        }

        for (int i = 31; i >= 0; --i) {
            if (ba[i] || bb[i]) {
                if (bb[i] && !ba[i]) {
                    std::cout << -1 << '\n';
                    return;
                }
                break;
            }
        }

        std::vector<int> nums;
        for (int i = 0; i < 32; ++i) {
            if (ba[i] ^ bb[i]) {
                nums.push_back(1 << i);
            }
        }

        std::cout << nums.size() << '\n';
        for (const auto num : nums) {
            std::cout << num << ' ';
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
