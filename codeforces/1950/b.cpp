#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    n *= 2;
    for (int i = 0; i < n; i++) {
        char ch = i / 2 % 2 ? '.' : '#';
        for (int j = 0; j < n / 2; j++) {
            std::cout << ch << ch;
            ch = ch == '#' ? '.' : '#';
        }
        std::cout << '\n';
    }
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
