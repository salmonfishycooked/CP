/**
* 区间操作 - Intervals 类
*
* 方法说明：
* 1. void merge(std::vector<std::pair<int, int>> &intervals)
*    合并区间，将其变成一个无重叠的有序区间序列（请确保区间有效，即对于任意区间[l, r]，都有 l <= r)，时间复杂度：O(n)
*/

#include <bits/stdc++.h>

using i64 = long long;

class Intervals {
public:
    static void merge(std::vector<std::pair<int, int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());

        int curPtr = 0, n = (int) intervals.size();
        for (int i = 0; i < n; i++) {
            int l = intervals[i].first, r = intervals[i].second;
            while (i < n - 1 && r >= intervals[i + 1].first) {
                i += 1;
                r = std::max(r, intervals[i].second);
            }
            intervals[curPtr++] = {l, r};
        }
        intervals.resize(curPtr);
    }
};
