#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = (int) s.length();

    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        int p1 = minIdx, p2 = i;
        for (int cnt = 0; cnt < n; cnt++) {
            if (s[p2] > s[p1]) { break; }
            if (s[p2] < s[p1]) {
                minIdx = i;
                break;
            }
            p1 = (p1 + 1) % n;
            p2 = (p2 + 1) % n;
        }
    }

    int p = minIdx;
    for (int cnt = 0; cnt < n; cnt++) {
        std::cout << s[p];
        p = (p + 1) % n;
    }
    std::cout << '\n';
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
