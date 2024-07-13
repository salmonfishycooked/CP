#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::map<int, std::vector<int>> m;
    for (auto num : a) {
        m[num % k].push_back(num);
    }

    if (n % 2 == 0) {
        i64 ans = 0;
        for (auto &[remain, vec] : m) {
            if (vec.size() % 2 == 1) {
                std::cout << -1 << '\n';
                return;
            }
            for (int i = vec.size() - 1; i >= 1; i -= 2) {
                ans += (vec[i] - vec[i - 1]) / k;
            }
        }

        std::cout << ans << '\n';
        return;
    }

    i64 oddVec = 0;
    for (auto &[remain, vec] : m) {
        if (vec.size() % 2 == 1) {
            if (oddVec > 0) {
                std::cout << -1 << '\n';
                return;
            }
            oddVec += 1;
        }
    }

    i64 ans = 0;
    for (auto &[remain, vec] : m) {
        if (vec.size() % 2 == 1 && vec.size() > 1) {
            std::vector<i64> pre(vec.size());
            for (int i = 2; i < vec.size(); i++) {
                pre[i] = pre[i - 1];
                if (i % 2 == 0) {
                    pre[i] += vec[i - 1] - vec[i - 2];
                }
            }

            i64 sum1 = pre[vec.size() - 1];
            i64 mnDiff = LONG_LONG_MAX;
            for (int i = 0; i < vec.size(); i++) {
                if (i % 2 == 0) {
                    mnDiff = std::min(mnDiff, pre[i] * 2 + vec[vec.size() - 1] - vec[i] - sum1);
                } else {
                    mnDiff = std::min(mnDiff, pre[i] * 2 + vec[vec.size() - 1] + vec[i] - vec[i - 1] * 2 - sum1);
                }
            }
            ans += mnDiff / k;
            continue;
        }
        for (int i = vec.size() - 1; i >= 1; i -= 2) {
            ans += (vec[i] - vec[i - 1]) / k;
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
