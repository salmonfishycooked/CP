#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, k;
    std::cin >> n >> k;

    int mx;
    for (int i = 1, r; i <= n; i++) {
        std::cout << "? " << 1 << ' ' << n * i << '\n' << std::flush;
        std::cin >> r;
        if (r == n) {
            mx = i;
            break;
        }
    }

    int result;
    for (int i = n / k; i >= 1; i--) {
        int cur = 1, divided = 0;
        while (cur <= n) {
            std::cout << "? " << cur << ' ' << i * mx << '\n' << std::flush;
            std::cin >> cur;
            if (cur == n + 1) { break; }

            divided += 1;
            cur += 1;
            if (divided == k) {
                if (cur == n + 1) {
                    std::cout << "! " << i * mx << '\n' << std::flush;
                    std::cin >> result;
                    return;
                }
                break;
            }
        }
    }

    std::cout << "! " << -1 << '\n' << std::flush;
    std::cin >> result;
};

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
