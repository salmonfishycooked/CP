#include <bits/stdc++.h>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
        d[i] = (d[i] % (a + b)) == 0 ? a + b : (d[i] % (a + b));
    }
    std::sort(d.begin(), d.end());

    int canMove = a - 1, needMove = 0;
    for (int i = 1; i < n; i++) {
        int cur = d[i] - d[0] + 1;
        if (cur <= a) {
            canMove = std::min(canMove, a - cur);
            continue;
        }
        needMove = std::max(needMove, a + b - cur + 1);
    }
    std::cout << (canMove >= needMove ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
