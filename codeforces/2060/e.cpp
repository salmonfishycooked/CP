#include <bits/stdc++.h>

using i64 = long long;

class DSU {
public:
    int n;
    std::vector<int> fa;

    explicit DSU(int n) : n(n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    bool merge(int u, int v) {
        int uFa = find(u), vFa = find(v);
        if (uFa == vFa) {
            return false;
        }

        fa[vFa] = uFa;
        return true;
    }

    int find(int u) {
        if (fa[u] != u) {
            return fa[u] = find(fa[u]);
        }
        return u;
    }
};

class Solution {
public:
    void solve() {
        int n, m1, m2;
        std::cin >> n >> m1 >> m2;

        std::vector<std::array<int, 2>> edges(n + 1);
        for (int i = 0, u, v; i < m1; i++) {
            std::cin >> u >> v;
            edges.push_back({u, v});
        }

        int cCnt2 = n;
        DSU dsu2(n);
        for (int i = 0, u, v; i < m2; i++) {
            std::cin >> u >> v;
            cCnt2 -= dsu2.merge(u, v);
        }

        int ans = 0, cCnt1 = n;
        DSU dsu1(n);
        for (auto [u, v] : edges) {
            if (dsu2.find(u) == dsu2.find(v)) {
                cCnt1 -= dsu1.merge(u, v);
            } else {
                ans += 1;
            }
        }
        ans += cCnt1 - cCnt2;

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
