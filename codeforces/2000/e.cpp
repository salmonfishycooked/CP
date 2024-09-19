#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int w;
    std::cin >> w;

    std::vector<int> a(w);
    for (auto &num : a) {
        std::cin >> num;
    }
    std::sort(a.begin(), a.end(), std::greater<>());

    std::vector<i64> seq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            seq.emplace_back(1LL * std::min({m - k + 1, m - j, j + 1, k}) * std::min({n - k + 1, n - i, i + 1, k}));
        }
    }
    std::sort(seq.begin(), seq.end(), std::greater<>());

    i64 ans = 0;
    for (int i = 0; i < w; i++) {
        ans += 1LL * seq[i] * a[i];
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
