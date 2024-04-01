#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;

    int num;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num % m == 0) {
            std::cout << num / m << ' ';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
