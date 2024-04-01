#include <bits/stdc++.h>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a + 1 != c) {
        std::cout << -1 << '\n';
        return;
    }

    std::queue<int> q;
    q.push(0);
    c -= 1;
    while (true) {
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        int height = q.front();
        q.pop();
        if (a > 0) {
            q.push(height + 1);
            q.push(height + 1);
            a -= 1;
            c -= 1;
            continue;
        }
        q.push(height + 1);
        b -= 1;
    }

    int ans = 0;
    while (!q.empty()) {
        ans = std::max(ans, q.front());
        q.pop();
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
