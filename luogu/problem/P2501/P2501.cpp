#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i] = a[i] - i;
    }

    int stayLen = 0;
    std::vector<int> l(n + 1, INT_MAX), f(n + 1);
    l[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        int idx = std::upper_bound(l.begin(), l.end(), b[i]) - l.begin();
        l[idx] = b[i];
        stayLen = std::max(stayLen, idx);
        f[i + 1] = idx;
    }

    i64 ans = LONG_LONG_MAX;
    std::vector<i64> g(n + 1, LONG_LONG_MAX);
    std::vector<i64> pre(n + 1), suf(n + 1);
    std::vector<int> fIdx[n + 1];
    fIdx[0].push_back(0);
    g[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j : fIdx[f[i] - 1]) {
            if (j != 0 && b[j - 1] > b[i - 1]) { continue; }
            int leftV = j == 0 ? INT_MIN : b[j - 1], rightV = b[i - 1];
            pre[j] = 0, suf[i] = 0;
            for (int k = j + 1; k <= i - 1; k++) {
                pre[k] = pre[k - 1] + std::abs(b[k - 1] - leftV);
            }
            for (int k = i - 1; k >= j + 1; k--) {
                suf[k] = suf[k + 1] + std::abs(b[k - 1] - rightV);
            }

            i64 changed = LONG_LONG_MAX;
            for (int k = j; k <= i - 1; k++) {
                changed = std::min(changed, pre[k] + suf[k + 1]);
            }
            g[i] = std::min(g[i], g[j] + changed);

            if (f[i] == stayLen) {
                i64 afterChanged = 0;
                for (int k = i + 1; k <= n; k++) {
                    afterChanged += b[i - 1] - b[k - 1];
                }
                ans = std::min(ans, g[i] + afterChanged);
            }
        }
        fIdx[f[i]].push_back(i);
    }

    std::cout << n - stayLen << '\n' << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
