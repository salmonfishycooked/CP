#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> factors[500001];

void solve() {
    int n;
    std::cin >> n;

    i64 ans = 0;
    std::vector<int> a[n + 1], b[n + 1];
    for (int i = 1, num; i <= n; i++) {
        std::cin >> num;
        int factor = std::gcd(num, i);
        if (factor == i) { ans -= 1; }

        a[i / factor].push_back(num / factor);
        b[num / factor].push_back(i / factor);
    }

    std::vector<int> cnt(n + 1);
    for (int x1 = 1; x1 <= n; x1++) {
        if (a[x1].empty()) { continue; }

        for (int y2 = x1; y2 <= n; y2 += x1) {
            for (auto x2 : b[y2]) {
                cnt[x2] += 1;
            }
        }
        for (auto y1 : a[x1]) {
            for (auto factor : factors[y1]) {
                ans += cnt[factor];
            }
        }

        for (int y2 = x1; y2 <= n; y2 += x1) {
            for (auto x2 : b[y2]) {
                cnt[x2] -= 1;
            }
        }
    }

    std::cout << ans / 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 1; i <= 500000; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j != 0) { continue; }
            int another = i / j;
            factors[i].push_back(j);
            if (another != j) {
                factors[i].push_back(another);
            }
        }
    }

    while (t--) {
        solve();
    }

    return 0;
}
