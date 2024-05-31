/**
 * 线段树 - 非 Lazy 版本
 * 单点修改，区间查询（分治）
 * 数组元素编号：1~n，注意传入的数组元素编号是从 0 开始的，长度为 n。
 *
 * 方法说明：
 * 1. void change(int id, int l, int r, int pos, T val)，将 pos 位置的值修改为 val（或者是其他修改方法，比如增量修改），注意这里 pos 范围为 1~n。
 *    使用示例: change(1, 1, n, 5, 10)，就是从 id 为 1 的线段树节点开始查找（该线段树掌管 1~n 区间的信息），将位置为 5 的元素修改成对应值。
 * 2. Info query(int id, int l, int r, int ql, int qr)，查询区间 [ql, qr] 上的信息。
 *    使用示例: query(1, 1, n, 4, 10)，就是从 id 为 1 的线段树节点开始查找（该线段树掌管 1~n 区间的信息），返回区间 [4, 10] 的信息。
 *
 * 参数说明：
 * 1. Info，即线段树的每个节点需要掌管的信息。其重载了+运算符，该运算里面是线段树的节点信息的更新逻辑。
 *
 * 下面模板给出的是求区间和的示例。
 */

#include <bits/stdc++.h>

using i64 = int64_t;

template <typename T = int>
class SegTree {
public:
    struct Info {
        i64 v;

        Info operator+(const Info &b) {
            Info info;
            info.v = v + b.v;

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
