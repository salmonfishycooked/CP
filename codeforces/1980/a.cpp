#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::map<char, int> mp;
    for (int i = 0; i < n; i++) {
        char ch;
        std::cin >> ch;
        mp[ch] += 1;
    }

    int ans = 0;
    for (int i = 'A'; i <= 'G'; i++) {
        ans += std::max(m - mp[i], 0);
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
