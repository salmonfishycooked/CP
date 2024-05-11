#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string str;
    std::cin >> str;

    char another;
    std::map<char, int> m;
    for (auto ch : str) {
        m[ch] += 1;
        if (ch != str[0]) {
            another = ch;
        }
    }

    if (m.size() == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::string ans;
    ans.push_back(another);
    m[another] -= 1;
    for (auto [ch, cnt] : m) {
        for (int i = 0; i < cnt; i++) {
            ans.push_back(ch);
        }
    }

    std::cout << "YES" << '\n';
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
