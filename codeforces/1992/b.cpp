#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    int mx = *std::max_element(a.begin(), a.end());
    bool visited = false;
    i64 ans = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == mx && !visited) {
            visited = true;
            continue;
        }
        ans += a[i] * 2 - 1;
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
