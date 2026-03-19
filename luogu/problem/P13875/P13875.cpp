#include <bits/stdc++.h>

using i64 = long long;

template <typename T = i64>
class Fenwick {
public:
    int n;
    std::vector<T> tree;

    explicit Fenwick(int _n) : n(_n) {
        tree.assign(n + 1, 0);
    }

    T sum(int x) {
        i64 res = 0;
        while (x) {
            res += tree[x];
            x -= lowBit(x);
        }
        return res;
    }

    void update(int x, T delta) {
        while (x <= n) {
            tree[x] += delta;
            x += lowBit(x);
        }
    }

    int lowBit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    void solve() {
        int n, s;
        std::cin >> n >> s;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) { std::cin >> a[i]; }

        const int m = *std::max_element(a.begin(), a.end());

        std::vector<std::vector<int>> tree(n);
        for (int i = 1, u, v; i < n; ++i) {
            std::cin >> u >> v;
            --u; --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        Fenwick<i64> bit(m);
        i64 ans = 0;
        auto dfs = [&](auto self, int me, int fa) -> void {
            ans += bit.sum(m) - bit.sum(a[me]);
            for (int v = a[me] + a[me]; v <= m; v += a[me]) {
                ans -= (bit.sum(v) - bit.sum(v - 1));
            }

            bit.update(a[me], 1);
            for (const auto &child : tree[me]) {
                if (child == fa) { continue; }
                self(self, child, me);
            }
            bit.update(a[me], -1);
        };
        dfs(dfs, s - 1, -1);

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}