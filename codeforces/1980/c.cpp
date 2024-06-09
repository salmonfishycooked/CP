#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        st.insert(b[i]);
    }

    int m;
    std::cin >> m;

    int lastB;
    std::map<int, int> d;
    for (int i = 0, v; i < m; i++) {
        std::cin >> v;
        d[v] += 1;
        if (i == m - 1) {
            lastB = v;
        }
    }

    std::map<int, int> need;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            need[b[i]] += 1;
        }
    }

    if (!st.count(lastB)) {
        std::cout << "NO" << '\n';
        return;
    }

    for (auto [num, cnt] : need) {
        if (cnt > d[num]) {
            std::cout << "NO" << '\n';
            return;
        }
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
