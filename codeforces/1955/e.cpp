#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    auto check = [&](int k) -> bool {
        std::string ss = s;
        std::vector<int> diff(n);
        int inverses = 0;
        for (int i = n - k; i >= 0; i--) {
            inverses -= diff[i + k - 1];
            if (ss[i + k - 1] == '1' && inverses % 2 == 0 || ss[i + k - 1] == '0' && inverses % 2 == 1) {
                continue;
            }
            inverses += 1;
            if (i > 0) {
                diff[i - 1] += 1;
            }
        }
        for (int i = k - 2; i >= 0; i--) {
            inverses -= diff[i];
            if (ss[i] == '0' && inverses % 2 == 0 || ss[i] == '1' && inverses % 2 == 1) {
                return false;
            }
        }

        return true;
    };

    int ans = 1;
    for (int i = n; i >= 2; i--) {
        if (check(i)) {
            ans = i;
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
