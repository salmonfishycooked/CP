/**
 * Manacher 算法 - 最大回文子串算法
 * 时间复杂度：O(n)
 *
 * 方法说明：
 * 1. int go(const std::string &ori) 返回字符串 ori 的最大回文子串长度
 *      此时 mxIdx 记录添加#后的字符串中拥有最大回文半径的字符下标，数组 r 则记录添加#后的字符串每个下标的最大回文半径。
 *      若要获得原字符串的最大回文子串，调用 s.substr(manacher.mxIdx / 2 - mxLen / 2, mxLen) 即可。(mxLen 为原串最大回文子串长度)
 *      判断原字符串[l, r]区间是否是回文，即判断 r[l + r + 1] - 1 >= b - a + 1。(因为 l + r + 1 对应添加#后的字符串的原[l, r]的回文中心)
 */

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
