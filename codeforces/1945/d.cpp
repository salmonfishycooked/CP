#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    i64 ans = 0;
    for (int i = n - 1; i > m - 1; i--) {
        if (b[i] <= a[i]) {
            ans += b[i];
            continue;
        }
        ans += a[i];
    }

    i64 more = a[m - 1], pre = b[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        more = std::min(more, pre + a[i]);
        pre += b[i];
    }
    ans += more;

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
