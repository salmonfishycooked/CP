#include <bits/stdc++.h>
#include <vector>

using i64 = long long;

class UnionFind {
private:
    std::vector<int> fa;

public:
    explicit UnionFind(int n) : fa(std::vector<int>(n)) {
        for (int i = 0; i < n; ++i) { fa[i] = i; }
    }

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    int uni(int x, int y) {
        const int fax = find(x), fay = find(y);
        fa[fay] = fax;

        return fax;
    }
};

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) { std::cin >> a[i]; }

        UnionFind uf(n);
        std::vector<int> grp_sz(n, 1);

        std::vector<std::vector<std::pair<int, int>>> f(n);
        for (int i = 1; i < n; ++i) {
            int diff = std::abs(a[i] - a[i - 1]);
            f[diff].emplace_back(i - 1, i);
        }

        std::vector<i64> cnt(n + 1);
        for (int k = n - 1; k >= 1; --k) {
            for (const auto [g1, g2] : f[k]) {
                const i64 sz1 = grp_sz[uf.find(g1)], sz2 = grp_sz[uf.find(g2)];
                const int new_fa = uf.uni(g1, g2);
                grp_sz[new_fa] = sz1 + sz2;
                cnt[k] += sz1 * sz2;
            }
            cnt[k] += cnt[k + 1];
        }

        for (int i = 1; i < n; ++i) {
            std::cout << cnt[i] << ' ';
        }
        std::cout << '\n';
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