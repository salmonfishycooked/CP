#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> b[i];
    }

    for (int m; q; q--) {
        std::cin >> m;
        auto idx = std::upper_bound(a.begin(), a.end(), m) - a.begin() - 1;
        i64 fromT = idx >= 0 ? b[idx] : 0, nextT = idx + 1 < k ? b[idx + 1] : 1e9;
        i64 from = idx >= 0 ? a[idx] : 0, nextFrom = idx + 1 < k ? a[idx + 1] : (n + 1);
        i64 miles = m - from;
        i64 nextNeed = miles * (nextT - fromT) / (nextFrom - from);

        std::cout << fromT + nextNeed << ' ';
    }
    std::cout << '\n';
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
