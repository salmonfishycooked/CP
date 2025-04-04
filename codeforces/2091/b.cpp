#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (auto &num : a) { std::cin >> num; }

        std::sort(a.begin(), a.end());

        int ans = 0;
        i64 base = 0, num = 0;
        for (int i = n - 1; i >= 0; i--) {
            base = a[i];
            num += 1;

            if (num * base >= x) {
                ans += 1;
                num = 0;
            }
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
