#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::vector<int> a(6), w(6);
    w[0] = 1, w[1] = 2, w[2] = 3, w[3] = 5, w[4] = 10, w[5] = 20;
    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
    }

    std::vector<bool> f(1001);
    f[0] = true;
    for (int i = 1; i <= 6; i++) {
        int remain = a[i - 1];
        for (int j = 1; j <= remain; j <<= 1) {
            for (int k = 1000; k >= w[i - 1] * j; k--) {
                f[k] = f[k] || f[k - w[i - 1] * j];
            }
            remain -= j;
        }
        for (int k = 1000; k >= w[i - 1] * remain; k--) {
            f[k] = f[k] || f[k - w[i - 1] * remain];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        if (f[i]) {
            cnt += 1;
        }
    }

    std::cout << "Total=" << cnt << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
