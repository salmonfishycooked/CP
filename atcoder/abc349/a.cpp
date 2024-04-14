#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    int tmp, ans = 0;
    for (int i = 1; i < n; i++) {
        std::cin >> tmp;
        ans += tmp;
    }

    std::cout << -ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
