#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 9999 << '\n';
        for (int a = 2; a <= 10000; a++) {
            std::cout << a << ' ' << a - 1 << '\n';
        }
        return;
    }

    std::vector<int> digits;
    for (int i = n; i > 0; i /= 10) {
        digits.push_back(i % 10);
    }
    std::reverse(digits.begin(), digits.end());
    int digCnt = digits.size();

    std::vector<std::pair<int, int>> ans;
    for (int diff = 1; ; diff++) {
        i64 num = 0;
        for (int i = 0, ptr = 0; i < diff; i++) {
            num *= 10;
            num += digits[ptr];
            ptr = (ptr + 1) % digCnt;
        }

        i64 a = (num - diff) / (n - digCnt);
        if (a > 10000) { break; }
        i64 b = digCnt * a - diff;
        if (a != 0 && b != 0 && a * n - b == num) {
            ans.emplace_back(a, b);
        }
    }

    std::cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        std::cout << a << ' ' << b << '\n';
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
