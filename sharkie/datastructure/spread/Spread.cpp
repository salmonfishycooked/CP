/**
 * 离散化 (Spread)
 * 将数组 arr 的所有数进行离散化处理【注意传入的 arr 必须是非降序排列！】
 * 并查询某个值 v 在离散化后的数组中的排名，排名从 0 开始。
 *
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 *
 * 方法说明：
 * 1. int getRank(int v) 返回值 v 在 arr 中的大小排名
 */

#include <bits/stdc++.h>

class Spread {
public:
    std::vector<int> ele;

    explicit Spread(std::vector<int> &arr) {
        init(arr);
    }

    int getRank(int v) {
        return std::lower_bound(ele.begin(), ele.end(), v) - ele.begin();
    }
private:
    void init(std::vector<int> &arr) {
        auto n = arr.size();
        ele.reserve(n);
        for (int i = 0; i < n; ) {
            ele.push_back(arr[i]);
            int next = i + 1;
            while (next < n && arr[next] == arr[i]) {
                next++;
            }
            i = next;
        }
    }
};
