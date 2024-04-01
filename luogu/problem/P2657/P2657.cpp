#include <bits/stdc++.h>

using i64 = long long;

int cal(int num) {
    std::vector<int> nums;
    for (; num; num /= 10) {
        nums.push_back(num % 10);
    }
    std::reverse(nums.begin(), nums.end());

    int n = (int) nums.size();

    int f[n][10][2][2];
    memset(f, 0xff, sizeof(f));
    std::function<int(int, int, int, int)> dfs;
    dfs = [&](int i, int pre, int limited, int isNum) -> int {
        if (i == n) {
            return isNum;
        }

        int &p = f[i][pre][limited][isNum];
        if (p != -1) {
            return p;
        }

        int res = 0;
        if (!isNum) {
            res = dfs(i + 1, 0, 0, 0);
        }
        for (int j = 0; j < 10; j++) {
            if (j == 0 && !isNum) {
                continue;
            }
            if (limited && j > nums[i]) {
                break;
            }

            if (!isNum || std::abs(pre - j) >= 2) {
                res += dfs(i + 1, j, (limited == 1 && j == nums[i]) ? 1 : 0, 1);
            }
        }

        return p = res;
    };

    return dfs(0, 0, 1, 0);
}

void solve() {
    int a, b;
    std::cin >> a >> b;

    std::cout << cal(b) - cal(a - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
