#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, std::priority_queue<int, std::vector<int>, std::greater<>>> m;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        m[a[i] >> 2].push(a[i]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << m[a[i] >> 2].top() << ' ';
        m[a[i] >> 2].pop();
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
