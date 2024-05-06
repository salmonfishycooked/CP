#include <bits/stdc++.h>

using i64 = int64_t;

struct Node {
    int id, v;
};

bool cmp(const Node &a, const Node &b) {
    return a.v > b.v;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<Node>> a(3, std::vector<Node>(n));
    int tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a[0][i] = {i, tmp};
    }
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a[1][i] = {i, tmp};
    }
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a[2][i] = {i, tmp};
    }
    std::sort(a[0].begin(), a[0].end(), cmp);
    std::sort(a[1].begin(), a[1].end(), cmp);
    std::sort(a[2].begin(), a[2].end(), cmp);

    auto cal = [&](int k1, int k2, int k3) -> int {
        int cur = a[k1][0].v;
        int k2choice;
        if (a[k2][0].id == a[k1][0].id) {
            cur += a[k2][1].v;
            k2choice = 1;
        } else {
            cur += a[k2][0].v;
            k2choice = 0;
        }
        if (a[k3][0].id == a[k1][0].id) {
            if (a[k3][1].id == a[k2][k2choice].id) {
                cur += a[k3][2].v;
            } else {
                cur += a[k3][1].v;
            }
            return cur;
        }
        if (a[k3][0].id == a[k2][k2choice].id) {
            if (a[k3][1].id == a[k1][0].id) {
                cur += a[k3][2].v;
            } else {
                cur += a[k3][1].v;
            }
            return cur;
        }
        cur += a[k3][0].v;
        return cur;
    };

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < 3; k++) {
                if (k == i || k == j) {
                    continue;
                }
                ans = std::max(ans, cal(i, j, k));
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