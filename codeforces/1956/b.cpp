#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    std::set<int> s;
    for (int i = 0, tmp; i < n; i++) {
        std::cin >> tmp;
        if (s.count(tmp)) {
            ans += 1;
            continue;
        }
        s.insert(tmp);
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
