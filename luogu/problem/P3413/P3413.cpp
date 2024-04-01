#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

bool valid(std::string &s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
            return true;
        }
    }

    return false;
}

int cal(std::string &s) {
    int n = (int) s.size();

    int f[n][10][10][2];
    memset(f, 0xff, sizeof(f));
    std::function<int(int, int, int, int, int, int)> dfs;
    dfs = [&](int i, int limited, int leading, int pre, int pre2, int ok) -> int {
        if (i == n) { return ok; }

        if (!limited && !leading && pre != -1 && pre2 != -1 && f[i][pre][pre2][ok] != -1) {
            return f[i][pre][pre2][ok];
        }

        int res = 0;
        if (leading) {
            res = dfs(i + 1, 0, 1, -1, -1, 0);
        }

        for (int j = 0; j < 10; j++) {
            if (j == 0 && leading) { continue; }
            if (limited && j > s[i] - '0') { break; }

            int okk = ok || (pre != -1 && j == pre) || (pre2 != -1 && j == pre2);
            res = (res + dfs(i + 1, limited && j == s[i] - '0', 0, j, pre, okk)) % MOD;
        }

        if (!limited && !leading && pre != -1 && pre2 != -1) { f[i][pre][pre2][ok] = res; }

        return res;
    };

    return dfs(0, 1, 1, -1, -1, 0);
}

void solve() {
    std::string l, r;
    std::cin >> l >> r;

    std::cout << (cal(r) - cal(l) + valid(l) + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
