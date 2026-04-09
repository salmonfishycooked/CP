#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        i64 n, m, k;
        std::cin >> n >> m >> k;

        i64 ans = 0;
        i64 startIdx = 1, fullLevelCnt = 1, remain = n, leftBound = -1, rightBound = -1;
        while (remain > 0) {
            i64 endIdx = fullLevelCnt + startIdx - 1;
            if (startIdx <= k && k <= endIdx) {
                leftBound = k - startIdx + 1;
                rightBound = k - startIdx + 1;
            }

            if (leftBound != -1) {
                ans += std::max(std::min(remain - leftBound + 1, rightBound - leftBound + 1), 0LL);
                leftBound = m * (leftBound - 1) + 1;
                rightBound = m * rightBound;
            }

            startIdx += fullLevelCnt;
            remain -= fullLevelCnt;
            fullLevelCnt *= m;
        }

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}