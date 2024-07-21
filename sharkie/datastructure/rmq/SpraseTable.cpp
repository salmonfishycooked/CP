/**
 * 区间最值查询 - RMQ
 * Sparse Table
 * 数组编号从 0 开始，即 [0, n)
 * 建立 ST 的时间复杂度 O(nlogn)，查询最值操作的时间复杂度 O(1)
 *
 * 方法说明：
 * 1. SparseTable 构造函数应该传入需要被建立 ST 表的数组
 * 2. int query(int from, int to) 查询 [from, to] 上的信息
 *
 * 下面给出的模板中，f[i][j] 表示区间 [j, j + 2^i - 1] 上的最大值，故 query 返回的信息是区间最大值
 */

#include <bits/stdc++.h>

class SparseTable {
public:
    int n;
    std::vector<std::vector<int>> f;

    SparseTable(std::vector<int> &arr) {
        n = (int)arr.size();
        int k = (int)std::log2(n);
        f.assign(k + 1, std::vector<int>(n));
        f[0] = arr;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                f[i][j] = std::max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int from, int to) {
        assert(from >= 0 && from <= to && to < n);
        int k = (int)std::log2(to - from + 1);
        return std::max(f[k][from], f[k][to - (1 << k) + 1]);
    }
};
