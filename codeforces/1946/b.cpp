#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n) {
    i64 res = 1;
    for (; n; n >>= 1) {
        if (n & 1) { res = res * x % MOD; }
        x = x * x % MOD;
    }

    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    i64 sum = 0, mx = 0, f0 = 0, f1;
    for (int i = 0; i < n; i++) {
        i64 num;
        std::cin >> num;
        sum = (sum + num + MOD) % MOD;
        f1 = std::max(f0 + num, num);
        f0 = f1;
        mx = std::max(mx, f1);
    }

    std::cout << (sum + mx % MOD * (power(2, k) - 1)) % MOD << '\n';
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
