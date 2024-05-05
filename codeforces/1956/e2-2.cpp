/**
 * 在原 e2 的解法上去掉了不必要的取模运算，降低运算常数。
 */

#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n == 2) {
        while (a[0] && a[1]) {
            a[1] = std::max(a[1] - a[0], 0);
            a[0] = std::max(a[0] - a[1], 0);
        }
        for (int i = 0; i < 2; i++) {
            if (a[i]) {
                std::cout << 1 << '\n' << i + 1 << '\n';
                return;
            }
        }
        std::cout << 0 << '\n' << '\n';
        return;
    }

    if (n == 3) {
        while (a[0] && a[1] && a[2]) {
            a[1] = std::max(a[1] - a[0], 0);
            a[2] = std::max(a[2] - a[1], 0);
            a[0] = std::max(a[0] - a[2], 0);
        }
        for (int i = 0; i < 3; i++) {
            if (a[i] == 0 && a[(i + 1) % n] != 0) {
                std::cout << 1 << '\n' << ((i + 1) % n) + 1 << '\n';
                return;
            }
        }
        std::cout << 0 << '\n' << '\n';
        return;
    }

    auto check = [&]() -> bool {
        for (int i = 0; i < n - 3; i++) {
            if (a[i] && a[i + 1] && a[i + 2] && a[i + 3]) {
                return true;
            }
        }
        for (int i = n - 3; i < n; i++) {
            if (a[i] && a[(i + 1) % n] && a[(i + 2) % n] && a[(i + 3) % n]) {
                return true;
            }
        }

        return false;
    };

    while (check()) {
        for (int i = 1; i < n; i++) {
            a[i] = std::max(a[i] - a[i - 1], 0);
        }
        a[0] = std::max(a[0] - a[n - 1], 0);
    }

    bool last = false;
    std::vector<int> ans;
    for (int i = 0; !last; ) {
        if (a[i] != 0) {
            i += 1;
            continue;
        }

        int nextZ = (i + 1) % n;
        while (a[nextZ] != 0) {
            nextZ = (nextZ + 1) % n;
        }

        int cnt = nextZ - i - 1;
        if (nextZ <= i) {
            last = true;
            cnt = nextZ + n - i - 1;
        }

        if (cnt > 0 && cnt <= 2) {
            ans.emplace_back((i + 1) % n + 1);
        }
        if (cnt == 3) {
            if (last) {
                for (int k = 1; k < nextZ; k++) {
                    a[k] = std::max(a[k] - a[k - 1], 0);
                }
            }
            ans.emplace_back((i + 1) % n + 1);
            i64 x = a[(i + 1) % n], y = a[(i + 2) % n], z = a[(i + 3) % n];
            i64 times = y / x - (y % x == 0);
            i64 sum = times * y - (times + 1) * times * x / 2;
            if (z > sum) {
                ans.emplace_back((i + 3) % n + 1);
            }
        }
        i = nextZ;
    }

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << '\n';
    for (auto idx : ans) {
        std::cout << idx << ' ';
    }
    std::cout << '\n';
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
