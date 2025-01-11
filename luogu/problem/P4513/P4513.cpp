#include <bits/stdc++.h>

using i64 = long long;

class SegTree {
public:
    struct Info { i64 ans, pre, suf, sum; };

    struct Node {
        int l, r;
        Info info;
    };
    std::vector<Node> seg;

    explicit SegTree(std::vector<int> &a) {
        auto n = a.size();
        seg.resize(n * 4);

        auto build = [&](auto self, int id, int l, int r) {
            seg[id].l = l, seg[id].r = r;
            if (l == r) {
                seg[id].info = {a[l - 1], a[l - 1], a[l - 1], a[l - 1]};
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
            seg[id].info = {val, val, val, val};
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) { change(id * 2, pos, val); }
        else { change(id * 2 + 1, pos, val); }
        update(id);
    }

    Info query(int id, int ql, int qr) {
        int l = seg[id].l, r = seg[id].r;
        if (l == ql && r == qr) {
            return seg[id].info;
        }

        int mid = (l + r) >> 1;
        if (qr <= mid) { return query(id * 2, ql, qr); }
        if (ql > mid) { return query(id * 2 + 1, ql, qr); }

        Info info1 = query(id * 2, ql, mid), info2 = query(id * 2 + 1, mid + 1, qr);
        return combineInfoAndInfo(info1, ql, mid, info2, mid + 1, qr);
    }

private:
    Info combineInfoAndInfo(const Info &info1, int l1, int r1, const Info &info2, int l2, int r2) {
        Info info;
        info.ans = std::max({info1.suf + info2.pre, info1.ans, info2.ans});
        info.pre = std::max(info1.pre, info1.sum + info2.pre);
        info.suf = std::max(info2.suf, info2.sum + info1.suf);
        info.sum = info1.sum + info2.sum;

        return info;
    }
};

class Solution {
public:
    void solve() {
        int n, s;
        std::cin >> n >> s;

        std::vector<int> score(n);
        for (int i = 0; i < n; i++) { std::cin >> score[i]; }

        SegTree tree(score);
        for (int i = 0, k, a, b; i < s; i++) {
            std::cin >> k >> a >> b;
            if (k == 1) { std::cout << tree.query(1, std::min(a, b), std::max(a, b)).ans << '\n'; }
            else { tree.change(1, a, b); }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
