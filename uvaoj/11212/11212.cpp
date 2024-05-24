#include <bits/stdc++.h>

using i64 = int64_t;

int solve(int n) {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](const std::vector<int> &nums) -> bool {
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                return false;
            }
        }

        return true;
    };

    auto transform = [&](std::vector<int> &nums, int from, int to, int targetIdx) -> void {
        std::vector<int> help(nums.begin(), nums.end());
        for (int i = from, j = to + 1; j <= targetIdx; i++, j++) {
            nums[i] = help[j];
        }
        for (int i = targetIdx - to + from, j = from; j <= to; i++, j++) {
            nums[i] = help[j];
        }
    };

    auto h = [&](const std::vector<int> &nums) -> int {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                cnt += 1;
            }
        }
        if (nums[0] != 1) {
            cnt += 1;
        }

        return cnt;
    };

    int mxDepth;
    auto dfs = [&](auto self, std::vector<int> &nums, int depth) -> bool {
        if(h(nums) > (mxDepth - depth) * 3) {
            return false;
        }
        if (depth == mxDepth) {
            return check(nums);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int pos = j + 1; pos < n; pos++) {
                    transform(nums, i, j, pos);
                    if (self(self, nums, depth + 1)) {
                        return true;
                    }
                    transform(nums, i, pos - j + i - 1, pos);
                }
            }
        }

        return false;
    };

    for (int i = 0; i <= 7; i++) {
        mxDepth = i;
        if (dfs(dfs, a, 0)) {
            return i;
        }
    }

    return 8;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    for (int i = 1; ; i++) {
        std::cin >> n;
        if (n == 0) { break; }
        std::cout << "Case " << i << ": " << solve(n) << '\n';
    }

    return 0;
}
