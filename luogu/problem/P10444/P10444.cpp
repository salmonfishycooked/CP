#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        m[a[i]] += 1;
    }

    std::sort(a.begin(), a.end());

    m[a[n - 1]] -= 1;
    for (int i = n - 2; i >= 0; i--) {
        m[a[i]] -= 1;
        int d = a[n - 1] - a[i];
        if (a[i] <= a[0] + d && m[a[0]] > 0 && m[a[0] + d] > 0) {
            std::cout << "Yes" << '\n';
            return;
        }
        m[a[i]] += 1;
    }
    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, id;
    std::cin >> T >> id;

    while (T--) {
        solve();
    }

    return 0;
}
