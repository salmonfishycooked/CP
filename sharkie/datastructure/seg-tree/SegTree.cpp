/**
 * 线段树 - 非 Lazy 版本
 * 单点修改，区间查询（分治）
 * 数组元素编号：1~n，注意传入的数组元素编号是从 0 开始的，长度为 n。
 *
 * 方法说明：
 * 1. void change(int id, int pos, T val)，将 pos 位置的值修改为 val（或者是其他修改方法，比如增量修改），注意这里 pos 范围为 1~n。
 *    使用示例: change(1, 5, 10)，就是从 id 为 1 的线段树节点开始查找（该线段树掌管 1~n 区间的信息，即树根），将位置为 5 的元素修改成对应值。
 * 2. Info query(int id, int ql, int qr)，查询区间 [ql, qr] 上的信息。
 *    使用示例: query(1, 4, 10)，就是从 id 为 1 的线段树节点开始查找（该线段树掌管 1~n 区间的信息，即树根），返回区间 [4, 10] 的信息。
 *
 * 参数说明：
 * 1. Node，即线段树的节点，里面存了对应的 Info 以及其掌管的区域 [l, r]。
 * 2. Info，即线段树的每个节点需要掌管的信息。
 *
 * 核心方法：
 * 1. 节点信息合并：
 *    Info combineInfoAndInfo(const Info &info1, int l1, int r1, const Info &info2, int l2, int r2)
 *    该方法会合并 info1 和 info2 的信息，其中 [l1, r1] 是 info1 掌管的区间，[l2, r2] 是 info2 掌管的区间。
 *
 * 下面模板给出的是求区间和的示例。
 */

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
        info.v = info1.v + info2.v;

        return info;
    }
};
