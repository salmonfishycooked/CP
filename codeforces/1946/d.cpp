#include <bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> aBits(31);
    for (auto num : a) {
        for (int i = 0; i < 31; i++) {
            if (num & (1 << i)) {
                aBits[i] += 1;
            }
        }
    }

    auto compress = [&](std::vector<std::pair<int, int>> intervals, int pos)
            -> std::vector<std::pair<int, int>> {
        for (int i = 0; i < n;) {
            if (!(a[i] & (1 << pos))) {
                intervals.emplace_back(i, i);
                i += 1;
                continue;
            }
            int r = i + 1;
            while (!(a[r] & (1 << pos))) { r += 1; }
            intervals.emplace_back(i, r);
            i = r + 1;
        }

        std::sort(intervals.begin(), intervals.end());

        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < intervals.size();) {
            int l = intervals[i].first, r = intervals[i].second;
            while (i < intervals.size() - 1 && r >= intervals[i + 1].first) {
                i += 1;
                r = std::max(r, intervals[i].second);
            }
            res.emplace_back(l, r);
            i += 1;
        }

        return res;
    };

    std::vector<std::pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        intervals[i].first = i, intervals[i].second = i;
    }

    int pos = 30;
    for (; pos >= 0; pos--) {
        if (x & (1 << pos)) { break; }
        if (aBits[pos] % 2 == 1) {
            std::cout << -1 << '\n';
            return;
        }
        intervals = compress(intervals, pos);
    }

    int ans = -1;
    for (; pos >= 0; pos--) {
        if (aBits[pos] % 2 == 1) {
            if (x & (1 << pos)) { continue; }
            std::cout << ans << '\n';
            return;
        }

        if (x & (1 << pos)) {
            ans = std::max(ans, (int) compress(intervals, pos).size());
            continue;
        }
        intervals = compress(intervals, pos);
    }
    ans = std::max(ans, (int) intervals.size());

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
