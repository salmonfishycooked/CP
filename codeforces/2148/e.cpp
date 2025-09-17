#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::map<int, int> m;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            m[a[i]] += 1;
        }

        std::vector<int> nums(*std::max_element(a.begin(), a.end()) + 1);
        for (auto &pair : m) {
            if (pair.second % k != 0) {
                std::cout << 0 << '\n';
                return;
            }
            pair.second /= k;
            nums[pair.first] = pair.second;
        }

        i64 ans = 0;
        for (int left = 0, right = -1; left < n; ++left) {
            while (right < n - 1 && nums[a[right + 1]] > 0) {
                right += 1;
                nums[a[right]] -= 1;
            }
            ans += right - left + 1;
            nums[a[left]] += 1;
        }

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
