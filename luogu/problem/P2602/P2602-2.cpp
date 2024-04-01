/**
 * 数位DP - 记忆化搜索写法
 */

#include <bits/stdc++.h>

using i64 = long long;

i64 cal(i64 num, int target) {
    std::vector<int> digits;
    for (; num; num /= 10) {
        digits.push_back(num % 10);
    }

    i64 f[digits.size()][14];
    memset(f, 0xff, sizeof(f));
    std::function<i64(int, int, int, int)> dfs;
    dfs = [&](int i, int cnt, int limited, int leading) -> i64 {
        if (i < 0) {
            return cnt;
        }

        i64 &p = f[i][cnt];
        if (!leading && !limited && p != -1) {
            return p;
        }

        i64 res = 0;
        if (leading) {
            res += dfs(i - 1, 0, 0, 1);
        }

        for (int j = 0; j < 10; j++) {
            if (leading && j == 0) {
                continue;
            }
            if (limited && j > digits[i]) {
                break;
            }

            res += dfs(i - 1, cnt + (j == target), limited && j == digits[i], 0);
        }

        if (!leading && !limited) {
            p = res;
        }

        return res;
    };

    return dfs(digits.size() - 1, 0, 1, 1);
}

void solve() {
    i64 a, b;
    std::cin >> a >> b;

    for (int i = 0; i < 10; i++) {
        std::cout << cal(b, i) - cal(a - 1, i) << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
