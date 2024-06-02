#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    int m = n - 2;

    int pre2, pre, cur;
    std::vector tps(3, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        pre2 = pre;
        pre = cur;
        std::cin >> cur;
        if (i >= 2) {
            tps[0][i - 2] = pre2;
            tps[1][i - 2] = pre;
            tps[2][i - 2] = cur;
        }
    }

    i64 ans = 0;

    std::vector<int> ids(m);
    for (int i = 0; i < m; i++) {
        ids[i] = i;
    }

    auto lowerBound = [&](int from, int to, int level, int v) -> int {
        int l = from - 1, r = to + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (tps[level][ids[mid]] >= v) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    };
    auto upperBound = [&](int from, int to, int level, int v) -> int {
        int l = from - 1, r = to + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (tps[level][ids[mid]] > v) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    };

    for (int pos = 0; pos <= 2; pos++) {
        i64 plus = 0;
        std::sort(ids.begin(), ids.end(), [&](int a, int b) -> bool {
            std::tuple<int, int, int> ta = {tps[pos][a], tps[(pos + 1) % 3][a], tps[(pos + 2) % 3][a]};
            std::tuple<int, int, int> tb = {tps[pos][b], tps[(pos + 1) % 3][b], tps[(pos + 2) % 3][b]};

            return ta < tb;
        });
        for (int i = 0; i < m; i++) {
            int from1 = lowerBound(0, m - 1, pos, tps[pos][ids[i]]);
            int to1 = upperBound(0, m - 1, pos, tps[pos][ids[i]]);

            int from2 = lowerBound(from1, to1 - 1, (pos + 1) % 3, tps[(pos + 1) % 3][ids[i]]);
            int to2 = upperBound(from1, to1 - 1, (pos + 1) % 3, tps[(pos + 1) % 3][ids[i]]);

            int from3 = lowerBound(from2, to2 - 1, (pos + 2) % 3, tps[(pos + 2) % 3][ids[i]]);
            int to3 = upperBound(from2, to2 - 1, (pos + 2) % 3, tps[(pos + 2) % 3][ids[i]]);

            plus += (to2 - from2) - (to3 - from3);
        }
        ans += plus / 2;
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
