#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int N = 1e6;

    void add(std::vector<i64> &nums, const i64 x) {
        const i64 sz = static_cast<i64>(nums.size());
        nums[0] += x;
        i64 carry = 0;
        for (i64 i = 0; i < sz; ++i) {
            const i64 v = nums[i] + carry;
            nums[i] = v % 10;
            carry = v / 10;
        }

        while (carry) {
            nums.push_back(carry % 10);
            carry /= 10;
        }
    }

    void mul(std::vector<i64> &nums, const i64 x) {
        const i64 sz = static_cast<i64>(nums.size());
        i64 carry = 0;
        for (i64 i = 0; i < sz; ++i) {
            const i64 v = nums[i] * x + carry;
            nums[i] = v % 10;
            carry = v / 10;
        }

        while (carry) {
            nums.push_back(carry % 10);
            carry /= 10;
        }
    }

    void solve() {
        int n;
        std::cin >> n;

        std::vector<i64> a(n), bitLen(n + 1);
        for (int i = 1; i <= n; ++i) {
            a[i - 1] = i;
            bitLen[i] = 32 - __builtin_clz(i);
        }

        std::sort(a.begin(), a.end(), [&](const i64 v1, const i64 v2) -> bool {
            return (v1 << bitLen[v2]) + v2 > (v2 << bitLen[v1]) + v1;
        });

        std::vector<i64> ans = {0};
        ans.reserve(N);
        for (const auto &num : a) {
            mul(ans, 1LL << bitLen[num]);
            add(ans, num);
        }

        for (auto it = ans.rbegin(); it != ans.rend(); ++it) { std::cout << *it; }
        std::cout << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}