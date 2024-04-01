#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k, d;
    std::cin >> n >> m >> k >> d;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<i64> costs(n);
    for (int i = 0; i < n; i++) {
        std::vector<i64> f(m);
        std::deque<int> q;
        f[0] = 1;
        q.push_back(0);
        for (int j = 1; j < m; j++) {
            // only indices >= j - d - 1 are valid
            while (!q.empty() && q.front() < j - d - 1) {
                q.pop_front();
            }
            f[j] = f[q.front()] + a[i][j] + 1;
            while(!q.empty() && f[q.back()] >= f[j]) {
                q.pop_back();
            }
            q.push_back(j);
        }
        costs[i] = f[m - 1];
    }

    std::vector<i64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + costs[i - 1];
    }

    i64 ans = LONG_LONG_MAX;
    for (int i = k; i <= n; i++) {
        ans = std::min(ans, sum[i] - sum[i - k]);
    }
    std::cout << ans << '\n';
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
