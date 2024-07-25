#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 1;
    std::vector<bool> f(x + 1);
    for (int i = 0; i < n - 1; ) {
        std::vector<int> existDiv = {1};
        f[1] = true;
        for (; i < n; i++) {
            if (x % a[i] != 0) { continue; }

            bool flag = true;
            std::vector<int> cur;
            for (auto div : existDiv) {
                i64 res = 1LL * div * a[i];
                if (res > x) { continue; }
                if (res == x) {
                    flag = false;
                    break;
                }
                if (!f[res] && x % res == 0) {
                    cur.push_back(res);
                }
            }
            for (auto div : cur) {
                existDiv.push_back(div);
                f[div] = true;
            }

            if (!flag) {
                ans += 1;
                break;
            }
        }

        for (auto div : existDiv) {
            f[div] = false;
        }
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
