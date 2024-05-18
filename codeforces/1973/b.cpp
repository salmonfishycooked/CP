#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](int v) -> bool {
        int finalV = 0;
        std::vector<int> digit(20);
        for (int i = 0; i < v; i++) {
            finalV |= a[i];
            for (int j = 0; j < 20; j++) {
                if (a[i] & (1 << j)) {
                    digit[j] += 1;
                }
            }
        }

        int curV = finalV;
        for (int i = v; i < n; i++) {
            int ex = i - v;
            curV |= a[i];
            for (int j = 0; j < 20; j++) {
                if (a[i] & (1 << j)) {
                    digit[j] += 1;
                }
            }
            for (int j = 0; j < 20; j++) {
                if (a[ex] & (1 << j)) {
                    digit[j] -= 1;
                    if (digit[j] == 0) {
                        finalV ^= (1 << j);
                    }
                }
            }

            if (curV != finalV) {
                return false;
            }
        }

        return true;
    };

    int l = 0, r = n + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    std::cout << r << '\n';
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
