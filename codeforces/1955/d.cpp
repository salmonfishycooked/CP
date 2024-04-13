#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, int> cntB;
    for (int i = 0, tmp; i < m; i++) {
        std::cin >> tmp;
        cntB[tmp] += 1;
    }

    std::map<int, int> cnt;
    int ans = 0, matched = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]] += 1;
        if (cnt[a[i]] <= cntB[a[i]]) { matched += 1; }
        if (i >= m - 1) {
            ans += matched >= k;
            cnt[a[i - m + 1]] -= 1;
            if (cntB[a[i - m + 1]] > cnt[a[i - m + 1]]) {
                matched -= 1;
            }
        }
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
