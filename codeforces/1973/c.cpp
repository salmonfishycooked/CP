#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    int mxIdx;
    std::vector<int> p(n);
    std::map<int, int> odd;
    std::map<int, int> even;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (i % 2) {
            even[p[i]] = i;
        } else {
            odd[p[i]] = i;
        }

        if (p[i] == n) {
            mxIdx = i;
        }
    }

    std::vector<int> q(n);
    if (mxIdx % 2) {
        int num = n;
        for (auto [x, idx] : even) {
            q[idx] = num;
            num -= 1;
        }
        num = n / 2;
        for (auto [x, idx] : odd) {
            q[idx] = num;
            num -= 1;
        }
    } else {
        int num = n;
        for (auto [x, idx] : odd) {
            q[idx] = num;
            num -= 1;
        }
        num = n / 2;
        for (auto [x, idx] : even) {
            q[idx] = num;
            num -= 1;
        }
    }

    for (auto num : q) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
};

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
