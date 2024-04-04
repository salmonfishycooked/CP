#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 2e5;
std::vector<int> frac(MAX_N + 1);

class ModInv {
public:
    const int mod;
    std::map<int, int> cache;

    explicit ModInv(int mod) : mod(mod) {}

    int operator()(int num) {
        auto it = cache.find(num);
        if (it != cache.end()) { return it->second; }

        return cache[num] = (int) power(num, mod - 2);
    }

    i64 power(i64 x, int n) const {
        i64 res = 1;
        for (; n; n >>= 1) {
            if (n & 1) { res = res * x % mod; }
            x = x * x % mod;
        }

        return res;
    }
};

ModInv inv(MOD);

i64 C(int a, int b) {
    return (i64) frac[b] * inv(frac[a]) % MOD * inv(frac[b - a]) % MOD;
}

void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;

    std::vector<int> p(m1), s(m2);
    std::vector<bool> flag(n);
    for (int i = 0; i < m1; i++) {
        std::cin >> p[i];
        flag[--p[i]] = true;
    }
    for (int i = 0; i < m2; i++) {
        std::cin >> s[i];
        flag[--s[i]] = true;
    }

    if (p[m1 - 1] != s[0]) {
        std::cout << 0 << '\n';
        return;
    }

    i64 ans = C(s[0], n - 1);
    for (int i = 0; i < s[0]; i++) {
        if (flag[i]) { continue; }
        ans = ans * i % MOD;
    }
    for (int i = n - 1; i > s[0]; i--) {
        if (flag[i]) { continue; }
        ans = ans * (n - i - 1) % MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    frac[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        frac[i] = (int) ((i64) frac[i - 1] * i % MOD);
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
