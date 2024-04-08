/**
 * HDU 1754 - I Hate It
 * 使用树状数组查询区间最大值，以及单点修改
 */

#include <bits/stdc++.h>

using i64 = int64_t;

template <typename T = i64>
class BIT {
public:
    int n;
    std::vector<T> tree;
    std::vector<T> &a;

    explicit BIT(int _n, std::vector<T> &_a) : n(_n), a(_a) {
        tree.assign(n + 1, 0);
    }

    T max(int l, int r) {
        i64 res = 0;
        while (l <= r) {
            if (r - lowBit(r) + 1 >= l) {
                res = std::max(res, tree[r]);
                r -= lowBit(r);
                continue;
            }
            res = std::max(res, a[r]);
            r--;
        }
        return res;
    }

    void update(int x, T v) {
        while (x <= n) {
            tree[x] = v;
            for (int i = 1; i < lowBit(x); i <<= 1) {
                tree[x] = std::max(tree[x], tree[x - i]);
            }
            x += lowBit(x);
        }
    }

    int lowBit(int x) {
        return x & -x;
    }
};

void solve(int n, int m) {
    std::vector<i64> a(n + 1);
    BIT tree(n, a);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        tree.update(i, a[i]);
    }

    while (m--) {
        char q;
        i64 x1, x2;
        std::cin >> q >> x1 >> x2;
        if (q == 'Q') {
            std::cout << tree.max(x1, x2) << '\n';
            continue;
        }
        a[x1] = x2;
        tree.update(x1, x2);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m) {
        solve(n, m);
    }

    return 0;
}
