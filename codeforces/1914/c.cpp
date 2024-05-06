#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int ans = 0, subMax = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        subMax = std::max(subMax, b[i]);
        cur += a[i];
        int subTimes = k - i - 1;
        if (subTimes < 0) {
            break;
        }
        ans = std::max(ans, cur + subTimes * subMax);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
