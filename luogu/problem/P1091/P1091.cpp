#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> f1(n), f2(n);
    for (int i = 0; i < n; i++) {
        f1[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                f1[i] = std::max(f1[i], f1[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        f2[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) {
                f2[i] = std::max(f2[i], f2[j] + 1);
            }
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, n - (f1[i] + f2[i] - 1));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
