#include <iostream>
#include <cmath>
#include <unordered_set>

void solve() {
    int a, b, l;
    std::cin >> a >> b >> l;
    int xMax = std::ceil(std::log(l) / std::log(a));
    int yMax = std::ceil(std::log(l) / std::log(b));

    std::unordered_set<int> s;
    int v1 = 1;
    for (int x = 0; x <= xMax; x++) {
        int v2 = 1;
        for (int y = 0; y <= yMax; y++) {
            int v = v1 * v2;
            if (v > l || l / v == 0) { break; }
            if (l % v == 0) { s.insert(l / v); }
            v2 *= b;
        }
        v1 *= a;
    }
    std::cout << s.size() << '\n';
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
