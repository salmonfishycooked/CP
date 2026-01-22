#include <bits/stdc++.h>

using i64 = long long;

template <typename T, typename Merge>
class SegTree {
public:
    explicit SegTree(const int n, const T &identity, Merge merge = Merge()) :
        SegTree(std::vector<T>(n, identity), identity, merge) {}

    explicit SegTree(const std::vector<T> &v, const T &identity, Merge merge = Merge()) :
        n(static_cast<int>(v.size())), merge(merge), identity(identity) {
        log = 0;
        while ((1 << log) < n) { ++log; }

        size = (1 << log);
        tree = std::vector<T>(2 * size, identity);

        for (int i = 0; i < n; ++i) { tree[size + i] = v[i]; }
        for (int i = size - 1; i >= 1; --i) { update(i); }
    }

    void set(int pos, T x) {
        assert(0 <= pos && pos < n);

        pos += size;
        tree[pos] = x;
        for (int i = 1; i <= log; ++i) { update(pos >> i); }
    }

    T get(const int pos) const {
        assert(0 <= pos && pos < n);

        return tree[pos + size];
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);

        T sml = identity, smr = identity;
        l += size, r += size;

        while (l < r) {
            if (l & 1) { sml = merge(sml, tree[l++]); }
            if (r & 1) { smr = merge(tree[--r], smr); }
            l >>= 1; r >>= 1;
        }

        return merge(sml, smr);
    }

    T allProd() const { return tree[ROOT]; }

private:
    static constexpr int HOLO = 0;
    static constexpr int ROOT = 1;

    const int n;
    int log, size;
    std::vector<T> tree;
    Merge merge;
    const T identity;

    void update(int id) { tree[id] = merge(tree[2 * id], tree[2 * id + 1]); }
};

struct SegData {
    int v;
};

struct Merge {
    SegData operator()(const SegData &d1, const SegData &d2) const {
        return {std::min(d1.v, d2.v)};
    }
};

class Solution {
public:
    void solve() {
        int n, q;
        std::cin >> n >> q;

        std::vector<SegData> a(n);
        for (int i = 0, v; i < n; ++i) {
            std::cin >> v;
            a[i] = {v};
        }

        SegTree<SegData, Merge> tree(a, {INT_MAX});
        while (q--) {
            int op, a, b;
            std::cin >> op >> a >> b;
            --a;

            if (op == 1) {
                tree.set(a, {b});
                continue;
            }

            --b;
            int l = tree.prod(a, b + 1).v - 1, r = b - a + 1;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                if (mid - tree.prod(a, a + mid + 1).v <= 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }

            if (l + 1 > r) {
                std::cout << 0 << '\n';
                continue;
            }

            std::cout << (tree.prod(a, a + l + 1).v == l ? 1 : 0) << '\n';
        }
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