#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i < n - 1; i++) {
        a[i] -= a[i - 1] * 2;
        a[i + 1] -= a[i - 1];
        if (a[i] < 0) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    if (a[n - 2] != 0 || a[n - 1] != 0) {
        std::cout << "NO" << '\n';
        return;
    }
    std::cout << "YES" << '\n';
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
