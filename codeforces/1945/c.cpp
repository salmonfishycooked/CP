#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    double cal = INT_MAX;
    int idx = -1, left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            right += 1;
        }
    }

    for (int i = 0; i <= n; i++) {
        if (i > 0 && a[i - 1] == '0') {
            left += 1;
        }
        if (i > 0 && a[i - 1] == '1') {
            right -= 1;
        }

        int leastL = std::ceil((double) i / 2), leastR = std::ceil((double) (n - i) / 2);
        if (left >= leastL && right >= leastR && cal > std::abs((double) n / 2 - i)) {
            idx = i;
            cal = std::abs((double) n / 2 - i);
        }
    }

    std::cout << idx << '\n';
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
