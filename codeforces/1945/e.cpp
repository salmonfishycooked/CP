#include <bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int l = 1, r = n + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (a[l] == x) {
        std::cout << 0 << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            std::cout << 1 << '\n' << i << ' ' << l << '\n';
            return;
        }
    }
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
