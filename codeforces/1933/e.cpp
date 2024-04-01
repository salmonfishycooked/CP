#include <iostream>
#include <vector>

typedef long long i64;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> sections(n + 1);
    for (int i = 1; i <= n; i++) { std::cin >> sections[i]; }

    std::vector<i64> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + sections[i]; }

    auto upperBound = [&](i64 val) -> int {
        int l = -1, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (pre[mid] > val) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    };

    i64 q, l, u;
    std::cin >> q;
    while (q--) {
        std::cin >> l >> u;
        int idx = upperBound(u + pre[l - 1]);
        if (idx == n + 1) {
            std::cout << idx - 1 << ' ';
            continue;
        }

        i64 v1 = u * (u + 1) / 2 - (pre[idx] - pre[l - 1] - u) * (pre[idx] - pre[l - 1] - u - 1) / 2;
        i64 v2 = (2 * u - pre[idx - 1] + pre[l - 1] + 1) * (pre[idx - 1] - pre[l - 1]) / 2;
        if (idx - 1 >= l && v2 >= v1) {
            std::cout << idx - 1 << ' ';
            continue;
        }
        std::cout << idx << ' ';
    }
    std::cout << '\n';
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
