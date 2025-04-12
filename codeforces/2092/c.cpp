#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<i64> a(n);
        for (auto &num : a) { std::cin >> num; }

        i64 ans = 0, sum = 0, oddCnt = 0, flag = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, a[i]);
            sum += a[i];
            oddCnt += (a[i] % 2 == 1);
            if (a[i] % 2 != a[0] % 2) { flag = 1; }
        }
        if (flag) { ans = std::max(ans, sum - oddCnt + 1); }

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
