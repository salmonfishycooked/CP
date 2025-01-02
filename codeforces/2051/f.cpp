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

class Solution {
public:
    void solve() {
        int n, m, q;
        std::cin >> n >> m >> q;

        std::vector<std::pair<int, int>> intervals = {{m, m}};
        for (int i = 0, idx; i < q; i++) {
            std::cin >> idx;
            std::vector<std::pair<int, int>> waitIntervals;
            for (int j = 0; j < intervals.size(); j++) {
                if (idx >= intervals[j].first && idx <= intervals[j].second) {
                    if (intervals[j].first == intervals[j].second) {
                        intervals.erase(intervals.begin() + j);
                        j -= 1;
                    }
                    waitIntervals.emplace_back(1, 1);
                    waitIntervals.emplace_back(n, n);
                } else if (idx < intervals[j].first) {
                    intervals[j].first = std::max(1, intervals[j].first - 1);
                } else {
                    intervals[j].second = std::min(n, intervals[j].second + 1);
                }
            }
            intervals.insert(intervals.end(), waitIntervals.begin(), waitIntervals.end());
            Intervals::merge(intervals);

            int ans = 0;
            for (auto &interval : intervals) {
                ans += interval.second - interval.first + 1;
            }

            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    int t;
    std::cin >> t;

    while (t--) {
        s.solve();
    }

    return 0;
}
