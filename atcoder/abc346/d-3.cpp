/**
 * 【最优解】
 * 记忆化搜索转递推（空间压缩）
 */

#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    i64 f00 = 0, f01 = 0, f10 = LONG_LONG_MAX / 2, f11 = LONG_LONG_MAX / 2;
    for (int i = 1; i < n; i++) {
        i64 o_f10 = f10, o_f00 = f00;
        f10 = std::min(f11 + (s[i - 1] == '0' ? c[i - 1] : 0), f00 + (s[i - 1] == '0' ? 0 : c[i - 1]));
        f11 = std::min(o_f10 + (s[i - 1] == '1' ? c[i - 1] : 0), f01 + (s[i - 1] == '1' ? 0 : c[i - 1]));
        f00 = f01 + (s[i - 1] == '0' ? c[i - 1] : 0);
        f01 = o_f00 + (s[i - 1] == '1' ? c[i - 1] : 0);
    }

    std::cout << std::min(f10 + (s[n - 1] == '0' ? 0 : c[n - 1]), f11 + (s[n - 1] == '1' ? 0 : c[n - 1])) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
