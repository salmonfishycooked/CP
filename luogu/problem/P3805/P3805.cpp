#include <bits/stdc++.h>

using i64 = long long;

class Manacher {
public:
    int mxIdx;
    std::vector<int> r;

    int go(const std::string &ori) {
        std::string str = "#";
        for (auto ch : ori) { str.push_back(ch); str.push_back('#'); }

        mxIdx = 0;
        int mid = 0, n = (int) str.size();
        r.assign(n, 1);
        for (int i = 1; i < n; i++) {
            int right = mid + r[mid] - 1;
            if (i < right) { r[i] = std::min(r[2 * mid - i], right - i + 1); }
            while (i - r[i] >= 0 && i + r[i] < n && str[i - r[i]] == str[i + r[i]]) { r[i] += 1; }

            if (i + r[i] > right) { mid = i; }
            if (r[i] > r[mxIdx]) { mxIdx = i; }
        }

        return r[mxIdx] - 1;
    }
};

class Solution {
public:
    void solve() {
        std::string str;
        std::cin >> str;

        Manacher manacher;
        std::cout << manacher.go(str) << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
