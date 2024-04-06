#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<i64> a(n), d(m), f(k);
    for (int i = 0; i < n; i++) { std::cin >> a[i]; }
    for (int i = 0; i < m; i++) { std::cin >> d[i]; }
    for (int i = 0; i < k; i++) { std::cin >> f[i]; }

    std::sort(f.begin(), f.end());

    std::map<int, int> diffs;
    int idx;
    for (int i = 1; i < n; i++) {
        if (diffs.empty() || a[i] - a[i - 1] > (--diffs.end())->first) {
            idx = i;
        }
        diffs[a[i] - a[i - 1]] += 1;
    }

    if ((--diffs.end())->second > 1) {
        std::cout << (--diffs.end())->first << '\n';
        return;
    }

    i64 lLimit = a[idx - 1], rLimit = a[idx], centerV = (rLimit + lLimit) >> 1;
    int ans = (--diffs.end())->first;
    diffs.erase(--diffs.end());
    for (int i = 0; i < m; i++) {
        auto it = std::lower_bound(f.begin(), f.end(), centerV - d[i]);
        if (it == f.end() || it != f.begin() && centerV - d[i] - *(it - 1) < d[i] + *it - centerV) {
            it--;
        }

        i64 v = d[i] + *it;
        if (v > lLimit && v < rLimit) {
            diffs[v - lLimit] += 1;
            diffs[rLimit - v] += 1;
            ans = std::min(ans, (--diffs.end())->first);
            diffs[v - lLimit] -= 1;
            diffs[rLimit - v] -= 1;
            if (diffs[v - lLimit] == 0) { diffs.erase(diffs.find(v - lLimit)); }
            if (diffs[rLimit - v] == 0) { diffs.erase(diffs.find(rLimit - v)); }
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
