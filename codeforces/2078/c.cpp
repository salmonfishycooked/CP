#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;
        n *= 2;

        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        std::sort(a.begin(), a.end(), std::greater<>());

        i64 v = 0;
        for (int i = n / 2; i >= 0; i--) { v += a[i]; }
        for (int i = n / 2 + 1; i < n; i++) { v -= a[i]; }

        int idx = 0;
        std::vector<i64> ans(n + 1);
        ans[1] = v;
        for (int i = 0; i <= n; i += 2) { ans[i] = a[idx++]; }
        for (int i = 3; i <= n; i += 2) { ans[i] = a[idx++]; }
        for (auto num : ans) { std::cout << num << ' '; }

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
