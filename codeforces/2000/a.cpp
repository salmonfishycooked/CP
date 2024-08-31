#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    if (s.length() <= 2 || !(s[0] == '1' && s[1] == '0') || (s.length() == 3 && s[2] < '2') || s[2] == '0') {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "YES" << '\n';
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
