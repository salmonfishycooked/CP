#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string str;
    std::cin >> str;

    int ans = 0;
    bool zeroOne = false;
    for (int i = 0; i < str.length(); i++) {
        if (i > 0 && str[i] == '1' && str[i - 1] == '0') {
            zeroOne = true;
        }
        while (i + 1 < str.length() && str[i + 1] == str[i]) {
            i += 1;
        }
        ans += 1;
    }

    std::cout << (ans - zeroOne) << '\n';
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
