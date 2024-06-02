#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }

    int sz = (int) st.size();
    std::vector<char> r(st.begin(), st.end());
    std::map<char, char> m;
    for (int i = 0; i <= sz / 2; i++) {
        m[r[i]] = r[sz - i - 1];
        m[r[sz - i - 1]] = r[i];
    }

    for (auto &ch : s) {
        ch = m[ch];
    }

    std::cout << s << '\n';
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