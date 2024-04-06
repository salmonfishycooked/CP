#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;

    int f0 = 1, f1;
    for (int i = 2; i <= n; i++) {
        if (f0 <= i - (k % i)) {
            f1 = f0 + (k % i);
        } else {
            f1 = f0 + (k % i) - i;
        }
        f0 = f1;
    }

    std::cout << f1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
