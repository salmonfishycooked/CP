#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int m, x;
    std::cin >> m >> x;

    i64 cur = 0;
    std::priority_queue<int> q;
    for (int i = 0, cost; i < m; i++, cur += x) {
        std::cin >> cost;
        if (cur >= cost) {
            q.push(cost);
            cur -= cost;
            continue;
        }
        if (!q.empty() && cost < q.top()) {
            cur += q.top() - cost;
            q.pop();
            q.push(cost);
        }
    }

    std::cout << q.size() << '\n';
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
