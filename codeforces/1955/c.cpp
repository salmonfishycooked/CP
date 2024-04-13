#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l = 0, r = n - 1, sunk = 0;
    while (sunk < n && k > 0) {
        if (sunk == n - 1) {
            sunk += a[l] <= k;
            break;
        }

        int round = std::min(a[l], a[r]);
        if (k >= round * 2) {
            k -= round * 2;
            a[l] -= round;
            a[r] -= round;
            if (a[l] == 0) {
                l += 1;
                sunk += 1;
            }
            if (a[r] == 0) {
                r -= 1;
                sunk += 1;
            }
            continue;
        }

        sunk += a[l] <= (k / 2 + (k % 2 == 1));
        break;
    }

    std::cout << sunk << '\n';
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
