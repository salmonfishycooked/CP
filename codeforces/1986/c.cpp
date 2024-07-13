#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::set<int> indices;
    for (int i = 0, tmp; i < m; i++) {
        std::cin >> tmp;
        indices.insert(tmp);
    }

    std::string c;
    std::cin >> c;

    std::sort(c.begin(), c.end());

    auto it = indices.begin();
    for (int i = 0; i < indices.size(); i++, it++) {
        s[*it - 1] = c[i];
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
