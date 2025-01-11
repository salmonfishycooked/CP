/**
 * 线段树 - Lazy 版本
 * 区间修改，区间查询（分治）
 * 数组元素编号：1~n，注意传入的数组元素编号是从 0 开始的，长度为 n。
 *
 * ⚠️注意：树根节点编号为 1
 *
 * 方法说明：
 * 1. void modify(int id, int ql, int qr, const Tag &tag)，将 [ql, qr] 区间内所有数进行修改，最后一个参数是修改需要的相关值。
 * 2. Info query(int id, int ql, int qr)，查询区间 [ql, qr] 上的信息。
 *
 * 参数说明：
 * 1. Info，即线段树的每个节点需要掌管的信息。
 * 2. Tag，即线段树的每个节点的标记。注意每个节点的 Tag 的默认值，其 Tag 里的每个参数在 Tag 的无参构造函数里面初始化！
 *
 * 下面模板给出的是区间加，区间查询的示例。
 * 例题网址：https://www.luogu.com.cn/problem/P3372
 * 调用函数 modify(1, 2, 10, {23}) 会将 [2, 10] 区间每个数加上 23。
 * 调用函数 query(1, 5, 8) 会返回 [5, 8] 的信息值，在这里 Info 存了区间和。
 */

#include <bits/stdc++.h>

using i64 = long long;

class SegTree {
public:
    struct Tag {
        i64 plus;

        Tag() : plus(0) {}
        Tag(i64 _plus) : plus(_plus) {}

        bool isNull() { return plus == 0; }
        void clear() { plus = 0; }
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
        int lc = id * 2, rc = lc + 1;
        seg[id].info = combineInfoAndInfo(seg[lc].info, seg[lc].l, seg[lc].r, seg[rc].info, seg[rc].l, seg[rc].r);
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
        if (qr <= mid) { modify(id * 2, ql, qr, tag); }
        else if (ql > mid) { modify(id * 2 + 1, ql, qr, tag); }
        else {
            modify(id * 2, ql, mid, tag);
            modify(id * 2 + 1, mid + 1, qr, tag);
        }
        update(id);
    }

    Info query(int id, int ql, int qr) {
        if (seg[id].l == ql && seg[id].r == qr) { return seg[id].info; }

        downTag(id);
        int mid = (seg[id].l + seg[id].r) >> 1;
        if (qr <= mid) { return query(id * 2, ql, qr); }
        else if (ql > mid) { return query(id * 2 + 1, ql, qr); }
        else {
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
