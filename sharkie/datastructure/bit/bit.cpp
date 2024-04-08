/**
 * 树状数组（Binary Indexed Tree）的实现
 * 元素下标范围：[1, n]
 * 下面的实现是求前缀和实现
 *
 * 方法说明：
 * 1. T sum(int x) 返回区间 [1, x] 的元素之和
 * 2. void update(int x, T delta) 将下标为 x 的元素增加 delta（delta 可正可负）
 * 3. int lowBit(int x) 返回 x 的二进制表示从右往左的第一个 1
 */

#include <bits/stdc++.h>

using i64 = int64_t;

template <typename T = i64>
class BIT {
public:
    int n;
    std::vector<T> tree;

    explicit BIT(int _n) : n(_n) {
        tree.assign(n + 1, 0);
    }

    T sum(int x) {
        i64 res = 0;
        while (x) {
            res += tree[x];
            x -= lowBit(x);
        }
        return res;
    }

    void update(int x, T delta) {
        while (x <= n) {
            tree[x] += delta;
            x += lowBit(x);
        }
    }

    int lowBit(int x) {
        return x & -x;
    }
};
