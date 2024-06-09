#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, f, k;
    std::cin >> n >> f >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int targetV = a[f - 1];
    std::sort(a.begin(), a.end());

    int idx = std::lower_bound(a.begin(), a.end(), targetV) - a.begin();
    int idx2 = std::upper_bound(a.begin(), a.end(), targetV) - a.begin();
    if (k >= n - idx) {
        std::cout << "YES" << '\n';
        return;
    }
    if (k <= n - idx2) {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "MAYBE" << '\n';
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
