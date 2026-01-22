/**
 * 非递归单点修改线段树
 * 查询范围 [0, n)
 *
 * @tparam T 线段树节点装载的数据类型
 * @tparam Merge 带有 T operator()(const T &a, const T &b) 函数的类（或 struct)，用来定义合并两个节点的逻辑
 *
 * 构造函数说明：
 * 1. SegTree(const int n, const T &identity, Merge merge), 用于初始值不确定的情况，预先开好能容纳 n 个元素的线段树
 * 2. SegTree(const std::vector<T> &v, const T &identity, Merge merge), 用于初始值确定的情况，即数组 v
 *
 * 某些参数说明：
 * 1. identity, 幺元，任意一个节点与幺元合并都等于原节点，即无作用，根据 merge 逻辑来合理设定
 *
 * 方法说明：
 * 1. void set(int pos, T x), 更新 pos 位置的值为 x (pos 范围[0, n))
 * 2. T get(const int pos), 查询 pos 位置的值 (pos 范围[0, n))
 * 3. T prod(int l, int r), 查询区间 [l, r) 的信息
 * 4. T allProd(), 返回总区间的信息, 即 [0, n)
 *
 * @note 下面给的示例 SegData 以及 Merge 是用来求区间和的，此时 identity 应该为 SegData{0}
 */

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
        return {d1.v + d2.v};
    }
};
