#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::vector<int> a;
    for (int tmp; std::cin >> tmp; ) {
        a.push_back(tmp);
    }
    int n = (int) a.size();

    int ans1 = 0;
    std::vector<int> f1(n + 1, 0);
    f1[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int l = -1, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (f1[mid] >= a[i - 1]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        f1[l + 1] = a[i - 1];
        ans1 = std::max(ans1, l + 1);
    }

    int ans2 = 0;
    std::vector<int> f2(n + 1, INT_MAX);
    f2[0] = 0;
    for (int i = 1; i <= n; i++) {
        int idx = std::lower_bound(f2.begin(), f2.end(), a[i - 1]) - f2.begin();
        f2[idx] = a[i - 1];
        ans2 = std::max(ans2, idx);
    }

    std::cout << ans1 << '\n' << ans2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
