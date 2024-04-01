#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans = n;
    for (int len = 1; len < n; len++) {
        if (n % len) { continue; }

        int unMatched = 0;
        for (int i = 0; i < len; i++) {
            int mx = 0;
            std::vector<int> cnt(26);
            for (int j = i; j < n; j += len) {
                cnt[s[j] - 'a'] += 1;
                mx = std::max(mx, cnt[s[j] - 'a']);
            }
            unMatched += (n / len) - mx;

            if (unMatched > 1) {
                break;
            }
        }

        if (unMatched <= 1) {
            ans = len;
            break;
        }
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
