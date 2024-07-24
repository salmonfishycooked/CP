#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<char> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int pos = -1, coldV = 0;
    while (pos < n) {
        int far = pos + m;
        if (far >= n) { break; }

        int logId = -1, waterId = -1;
        for (int j = pos + 1; j <= far; j++) {
            if (a[j] == 'L') {
                logId = j;
            } else if (a[j] == 'W') {
                waterId = j;
            }
        }

        if (logId != -1) {
            pos = logId;
        } else if (waterId != -1) {
            pos = waterId;
            while (pos < n && a[pos] == 'W') {
                pos += 1;
                coldV += 1;
            }
            if (pos < n && a[pos] == 'C') {
                std::cout << "NO" << '\n';
                return;
            }
        } else {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << (coldV <= k ? "YES" : "NO") << '\n';
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
