#include <bits/stdc++.h>

using i64 = int64_t;

class SegTree {
public:
    struct Tag {
        i64 plus;

        bool isNull() {
            return plus == 0;
        }

        void clear() {
            plus = 0;
        }
    };

    struct Info {
        i64 v;
    };

    struct Node {
        int l, r;
        Info info;
        Tag tag;
    };
    std::vector<Node> seg;

    explicit SegTree(std::vector<i64> &a) {
        int n = a.size();
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
        seg[id].info = combineInfoAndInfo(id * 2, id * 2 + 1);
    }

    void passTag(int id, const Tag &t) {
        seg[id].info = combineInfoAndTag(id, t);
        seg[id].tag = combineTagAndTag(id, t);
    }

    void downTag(int id) {
        if (seg[id].tag.isNull()) { return; }

        passTag(id * 2, seg[id].tag);
        passTag(id * 2 + 1, seg[id].tag);
        seg[id].tag.clear();
    }

    void modify(int id, int ql, int qr, const Tag &tag) {
        if (seg[id].l == ql && seg[id].r == qr) {
            passTag(id, tag);
            return;
        }

        downTag(id);
        int mid = (seg[id].l + seg[id].r) >> 1;
        if (qr <= mid) {
            modify(id * 2, ql, qr, tag);
        } else if (ql > mid) {
            modify(id * 2 + 1, ql, qr, tag);
        } else {
            modify(id * 2, ql, mid, tag);
            modify(id * 2 + 1, mid + 1, qr, tag);
        }
        update(id);
    }

    Info query(int id, int ql, int qr) {
        if (seg[id].l == ql && seg[id].r == qr) {
            return seg[id].info;
        }

        downTag(id);
        int mid = (seg[id].l + seg[id].r) >> 1;
        if (qr <= mid) {
            return query(id * 2, ql, qr);
        } else if (ql > mid) {
            return query(id * 2 + 1, ql, qr);
        } else {
            return combineInfoAndInfo(query(id * 2, ql, mid), query(id * 2 + 1, mid + 1, qr));
        }
    }

private:
    Info combineInfoAndInfo(int id1, int id2) {
        return combineInfoAndInfo(seg[id1].info, seg[id2].info);
    }

    Info combineInfoAndInfo(const Info &info1, const Info &info2) {
        Info info;
        info.v = info1.v + info2.v;

        return info;
    }

    Info combineInfoAndTag(int id1, const Tag &tag2) {
        int l = seg[id1].l, r = seg[id1].r;

        Info info = seg[id1].info;
        info.v = info.v + tag2.plus * (r - l + 1);

        return info;
    }

    Tag combineTagAndTag(int id1, const Tag &tag2) {
        const Tag &tag1 = seg[id1].tag;

        Tag tag;
        tag.plus = tag1.plus + tag2.plus;

        return tag;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 op, x, y, k;
    SegTree tree(a);
    while (m--) {
        std::cin >> op >> x >> y;
        if (op == 1) {
            std::cin >> k;
            tree.modify(1, x, y, {k});
        } else {
            std::cout << tree.query(1, x, y).v << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
