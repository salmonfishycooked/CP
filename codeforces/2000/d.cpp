#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> sum(n + 1);
    for (int i = 1, num; i <= n; i++) {
        std::cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    std::vector<char> ops(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> ops[i];
    }

    auto dfs = [&](auto self, int l, int r) -> i64 {
        if (l >= r) { return 0; }

        int leftL = l, rightR = r;
        while (leftL <= r && ops[leftL] != 'L') {
            leftL += 1;
        }
        while (rightR >= leftL && ops[rightR] != 'R') {
            rightR -= 1;
        }

        return self(self, leftL + 1, rightR - 1) + sum[rightR] - sum[leftL - 1];
    };

    std::cout << dfs(dfs, 1, n) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
