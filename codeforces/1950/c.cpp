#include <bits/stdc++.h>

void solve() {
    int h, m;
    char q;
    std::cin >> h >> q >> m;

    std::string s = "AM";
    if (h >= 12) {
        s = "PM";
        h -= 12;
    }
    if (h == 0) {
        h = 12;
    }

    std::cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << ' ' << s << '\n';
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
