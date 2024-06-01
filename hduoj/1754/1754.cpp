#include <bits/stdc++.h>

using i64 = int64_t;

class SegTree {
public:
    struct Info {
        i64 v;
    };

    struct Node {
        int l, r;
        Info info;
    };
    std::vector<Node> seg;

    explicit SegTree(std::vector<i64> &a) {
        auto n = a.size();
        seg.resize(n * 4);

        auto build = [&](auto self, int id, int l, int r) {
            seg[id].l = l, seg[id].r = r;
            if (l == r) {
                seg[id].info = {a[l - 1]};
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
        int lc = id * 2, rc = lc + 1;
        seg[id].info = combineInfoAndInfo(seg[lc].info, seg[lc].l, seg[lc].r, seg[rc].info, seg[rc].l, seg[rc].r);
    }

    void change(int id, int pos, i64 val) {
        int l = seg[id].l, r = seg[id].r;
        if (l == r) {
            seg[id].info.v = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) {
            change(id * 2, pos, val);
        } else {
            change(id * 2 + 1, pos, val);
        }
        update(id);
    }

    Info query(int id, int ql, int qr) {
        int l = seg[id].l, r = seg[id].r;
        if (l == ql && r == qr) {
            return seg[id].info;
        }

        int mid = (l + r) >> 1;
        if (qr <= mid) {
            return query(id * 2, ql, qr);
        } else if (ql > mid) {
            return query(id * 2 + 1, ql, qr);
        } else {
            Info info1 = query(id * 2, ql, mid), info2 = query(id * 2 + 1, mid + 1, qr);
            return combineInfoAndInfo(info1, ql, mid, info2, mid + 1, qr);
        }
    }

private:
    Info combineInfoAndInfo(const Info &info1, int l1, int r1, const Info &info2, int l2, int r2) {
        Info info;
        info.v = std::max(info1.v, info2.v);

        return info;
    }
};

void solve(int n, int m) {
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SegTree tree(a);
    while (m--) {
        char op;
        int x, y;
        std::cin >> op >> x >> y;

        if (op == 'Q') {
            std::cout << tree.query(1, x, y).v << '\n';
        } else {
            tree.change(1, x, y);
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
