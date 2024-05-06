#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    int ans = 0;
    std::unordered_map<int, int> m;
    char ch;
    for (int i = 0; i < n; i++) {
        std::cin >> ch;
        m[ch] += 1;
        if (m[ch] == ch - 'A' + 1) {
            ans += 1;
        }
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
