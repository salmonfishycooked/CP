#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < 5; i++) {
        if (a[0] < a[1]) {
            a[0] += 1;
            continue;
        }
        if (a[1] < a[2]) {
            a[1] += 1;
            continue;
        }
        a[2] += 1;
    }

    std::cout << a[0] * a[1] * a[2] << '\n';
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
