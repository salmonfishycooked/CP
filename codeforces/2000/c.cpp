#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    std::string s;
    for (int i = 0; i < m; i++) {
        std::cin >> s;

        int len = s.length();
        if (len != n) {
            std::cout << "NO" << '\n';
            continue;
        }

        std::map<char, int> mp1;
        std::map<int, char> mp2;
        bool ok = true;
        for (int j = 0; j < len; j++) {
            char ch = s[j] - 'a';
            if (mp1.count(ch) && mp1[ch] != a[j] || mp2.count(a[j]) && mp2[a[j]] != ch) {
                ok = false;
                break;
            }
            mp1[ch] = a[j];
            mp2[a[j]] = ch;
        }

        if (ok) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
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
