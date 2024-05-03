#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i - 1];
        for (int j = 1; j <= i; j++) {
            f[i] = std::max(f[i], f[j - 1] + (i - j + 1) * (i - j + 1));
        }
    }

    std::vector<std::pair<int, int>> intervals;
    int i = n;
    while (i > 0) {
        if (f[i - 1] + a[i - 1] == f[i]) {
            i -= 1;
            continue;
        }
        for (int j = i; j >= 1; j--) {
            if (f[j - 1] + (i - j + 1) * (i - j + 1) == f[i]) {
                intervals.emplace_back(j, i);
                i = j - 1;
                continue;
            }
        }
    }

    std::vector<std::pair<int, int>> ans;
    auto doit = [&](int i, int j) -> void {
        for (int k = i; k <= j; k++) {
            if (a[k - 1] != 0) {
                ans.emplace_back(k, k);
            }
        }

        auto rec = [&](auto self, int i, int j) -> void {
            for (int k = j - 1; k >= i; k--) {
                self(self, i, k);
                if (k - 1 >= i) {
                    ans.emplace_back(i, k - 1);
                }
            }
            ans.emplace_back(i, j);
        };
        rec(rec, i, j);
    };

    for (auto [x, y] : intervals) {
        doit(x, y);
    }

    std::cout << f[n] << ' ' << ans.size() << '\n';
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
