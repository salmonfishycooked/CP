#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        for (int j = 0; j < i + 1; j++) {
            std::cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    std::vector<int> f(n);
    f[0] = a[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = a[i].size() - 1; j >= 0; j--) {
            if (j == 0) {
                f[j] = f[j] + a[i][j];
                continue;
            }
            if (j == a[i].size() - 1) {
                f[j] = f[j - 1] + a[i][j];
                continue;
            }
            f[j] = std::max(f[j - 1], f[j]) + a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, f[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
