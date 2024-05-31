#include <bits/stdc++.h>

using i64 = int64_t;

template <typename T = int>
class SegTree {
public:
    struct Info {
        i64 v;

        Info operator+(const Info &b) {
            Info info;
            info.v = std::max(v, b.v);

            return info;
        }
    };
    std::vector<Info> seg;

    explicit SegTree(std::vector<T> &a) {
        int n = a.size();
        seg.resize(n * 4);

        auto build = [&](auto self, int id, int l, int r) {
            if (l == r) {
                seg[id] = {a[l - 1]};
                return;
            }

            int mid = (l + r) >> 1;
            self(self, id * 2, l, mid);
            self(self, id * 2 + 1, mid + 1, r);
            update(id);
        };
        build(build, 1, 1, n);
    }

    void update(int id) {
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    void change(int id, int l, int r, int pos, T val) {
        if (l == r) {
            seg[id] = {val};
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) {
            change(id * 2, l, mid, pos, val);
        } else {
            change(id * 2 + 1, mid + 1, r, pos, val);
        }
        update(id);
    }

    Info query(int id, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return seg[id];
        }

        int mid = (l + r) >> 1;
        if (qr <= mid) {
            return query(id * 2, l, mid, ql, qr);
        } else if (ql > mid) {
            return query(id * 2 + 1, mid + 1, r, ql, qr);
        } else {
            return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
        }
    }
};

void solve(int n, int m) {
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SegTree<i64> tree(a);
    while (m--) {
        char op;
        int x, y;
        std::cin >> op >> x >> y;

        if (op == 'Q') {
            std::cout << tree.query(1, 1, n, x, y).v << '\n';
        } else {
            tree.change(1, 1, n, x, y);
        }
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
