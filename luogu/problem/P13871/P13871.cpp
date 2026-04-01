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

class Kruskal {
public:
    struct Edge {
        int u, v, w;
    };

    int n;
    std::vector<Edge> edges;

    explicit Kruskal(const int n) : n(n), edges(std::vector<Edge>()) {}

    void addEdge(const int u, const int v, const int w) {
        edges.push_back({u, v, w});
    }

    int go() {
        int ret = 0;

        DSU dsu(n);
        std::sort(edges.begin(), edges.end(), [&](const Edge &e1, const Edge &e2) -> bool {
            return e1.w > e2.w;
        });
        for (const auto &edge : edges) {
            const int u = edge.u, v = edge.v, w = edge.w;
            if (dsu.find(u) == dsu.find(v)) { continue; }

            dsu.merge(u, v);
            ret += w;
        }

        return ret;
    }
};

class Solution {
public:
    int maxCommonSubstringLen(const std::string &str1, const std::string &str2) {
        const int n = static_cast<int>(str1.length());
        const int m = static_cast<int>(str2.length());

        int ans = 0;
        std::vector f(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    ans = std::max(ans, f[i][j]);
                }
            }
        }

        return ans;
    }

    void solve() {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::string> strs(n);
        for (int i = 0; i < n; ++i) { std::cin >> strs[i]; }

        Kruskal g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int w = std::min(m, maxCommonSubstringLen(strs[i] + strs[i], strs[j] + strs[j]));
                g.addEdge(i + 1, j + 1, w);
            }
        }

        std::cout << g.go() << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}