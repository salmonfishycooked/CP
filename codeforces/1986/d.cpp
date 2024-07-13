#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    if (n == 2) {
        std::cout << std::atoi(s.c_str()) << '\n';
        return;
    }

    if (n == 3) {
        int cond1 = std::atoi(s.substr(0, 2).c_str()) + (s[2] - '0');
        int cond2 = std::atoi(s.substr(0, 2).c_str()) * (s[2] - '0');
        int cond3 = std::atoi(s.substr(1, 2).c_str()) + (s[0] - '0');
        int cond4 = std::atoi(s.substr(1, 2).c_str()) * (s[0] - '0');
        std::cout << std::min({cond1, cond2, cond3, cond4}) << '\n';
        return;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            std::cout << 0 << '\n';
            return;
        }
        if (s[i] != '1') {
            sum += s[i] - '0';
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        int sumT = sum + std::atoi(s.substr(i - 1, 2).c_str());
        if (s[i - 1] != '1') {
            sumT -= s[i - 1] - '0';
        }
        if (s[i] != '1') {
            sumT -= s[i] - '0';
        }

        ans = std::min(ans, sumT);
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
