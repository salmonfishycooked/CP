/**
 * 组合数学
 */

#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 l, r;
    std::cin >> l >> r;

    std::vector<i64> pow10(13);
    pow10[0] = 1;
    for (int i = 1; i <= 12; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }

    std::vector<i64> ans(10);
    auto cal = [&](i64 n, int factor) {
        std::vector<int> nums;
        for (; n; n /= 10) {
            nums.push_back(n % 10);
        }
        std::reverse(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                ans[nums[j]] += factor * nums[i] * pow10[nums.size() - i - 1];
            }
            for (int j = 1; j < nums[i]; j++) {
                ans[j] += factor * pow10[nums.size() - i - 1];
            }
            if (i != 0 && nums[i]) {
                ans[0] += factor * pow10[nums.size() - i - 1];
            }

            if (i != nums.size() - 1) {
                for (int j = 1; j < 10; j++) {
                    ans[j] += factor * nums[i] * pow10[nums.size() - i - 2] * (nums.size() - i - 1);
                }
                if (i != 0) {
                    ans[0] += factor * nums[i] * pow10[nums.size() - i - 2] * (nums.size() - i - 1);
                }
            }

            if (i == 0) {
                if (nums.size() >= 2) {
                    ans[0] += factor * (nums[0] - 1) * (nums.size() - 1) * pow10[nums.size() - 2];
                }
                for (int j = 1; j < nums.size() - 1; j++) {
                    ans[0] += factor * 9 * (nums.size() - j - 1) * pow10[nums.size() - j - 2];
                }
            }
        }

        for (auto num : nums) {
            ans[num] += factor;
        }
    };

    cal(r, 1);
    cal(l - 1, -1);

    for (auto cnt : ans) {
        std::cout << cnt << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
