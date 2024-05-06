#include <bits/stdc++.h>

using i64 = int64_t;

struct Node {
    int v1, v2;
};

bool cmp(const Node &a, const Node &b) {
    return a.v1 + a.v2 > b.v1 + b.v2;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        b[i] = tmp;
    }

    std::vector<Node> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = {a[i], b[i]};
    }
    std::sort(c.begin(), c.end(), cmp);

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans += c[i].v1 - 1;
            continue;
        }
        ans -= c[i].v2 - 1;
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
