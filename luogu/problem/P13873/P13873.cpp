#include <bits/stdc++.h>
#include <vector>

using i64 = long long;

i64 power(const int a, int x, const int M) {
    i64 res = 1, weight = a;
    for (i64 msk = x; msk; msk >>= 1) {
        if (msk & 1) { res = (res * weight) % M; }
        weight = (weight * weight) % M;
    }

    return res;
}

class Rank {
public:
    std::vector<i64> nums;

    explicit Rank(const std::vector<i64> &a) : nums(a) {
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    }

    int size() { return nums.size(); }

    int operator()(const int v) {
        return std::upper_bound(nums.begin(), nums.end(), v) - nums.begin();
    }
};

class Solution {
public:
    static constexpr i64 MOD = 1e9 + 7;

    void solve() {
        int n, m, T;
        std::cin >> n >> m >> T;

        std::vector<i64> R(n), C(m);
        for (int i = 0; i < n; ++i) { std::cin >> R[i]; }
        for (int i = 0; i < m; ++i) { std::cin >> C[i]; }

        Rank rkR(R), rkC(C);
        std::vector<i64> cntR(rkR.size() + 1), cntC(rkC.size() + 1);
        for (const int &v : R) { cntR[rkR(v)] += 1; }
        for (const int &v : C) { cntC[rkC(v)] += 1; }

        std::vector<i64> cntRInv(rkR.size() + 1), cntCInv(rkC.size() + 1);
        for (int i = 1; i <= rkR.size(); ++i) { cntRInv[i] = power(cntR[i], MOD - 2, MOD); }
        for (int i = 1; i <= rkC.size(); ++i) { cntCInv[i] = power(cntC[i], MOD - 2, MOD); }

        std::vector<i64> prodR(rkR.size() + 1, 1), prodC(rkC.size() + 1, 1);
        for (int i = 1; i <= rkR.size(); ++i) { prodR[i] = prodR[i - 1] * cntR[i] % MOD; }
        for (int i = 1; i <= rkC.size(); ++i) { prodC[i] = prodC[i - 1] * cntC[i] % MOD; }

        std::vector<i64> prodRInv(rkR.size() + 1), prodCInv(rkC.size() + 1);
        for (int i = 1; i <= rkR.size(); ++i) { prodRInv[i] = power(prodR[i], MOD - 2, MOD); }
        for (int i = 1; i <= rkC.size(); ++i) { prodCInv[i] = power(prodC[i], MOD - 2, MOD); }

        std::vector<i64> fac(n + m + 10, 1), facInv(n + m + 10, 1);
        for (int i = 1; i < n + m + 10; ++i) { fac[i] = fac[i - 1] * i % MOD; }
        for (int i = 1; i < n + m + 10; ++i) { facInv[i] = power(fac[i], MOD - 2, MOD); }

        int x1, y1, x2, y2;
        while (T--) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (R[x2 - 1] < R[x1 - 1] || C[y2 - 1] < C[y1 - 1]) { std::cout << 0 << '\n'; continue; }
            if (R[x2 - 1] == R[x1 - 1] && x1 != x2) { std::cout << 0 << '\n'; continue; }
            if (C[y2 - 1] == C[y1 - 1] && y1 != y2) { std::cout << 0 << '\n'; continue; }

            const i64 r = rkR(R[x2 - 1]) - rkR(R[x1 - 1]);
            const i64 c = rkC(C[y2 - 1]) - rkC(C[y1 - 1]);

            const i64 rowMethods = (r == 0) ? 1 : (prodR[rkR(R[x2-1])] * prodRInv[rkR(R[x1-1])] % MOD) * cntRInv[rkR(R[x2-1])] % MOD;
            const i64 colMethods = (c == 0) ? 1 : (prodC[rkC(C[y2-1])] * prodCInv[rkC(C[y1-1])] % MOD) * cntCInv[rkC(C[y2-1])] % MOD;
            const i64 chooseMethods = ((fac[r + c] * facInv[r]) % MOD) * facInv[c] % MOD;

            const i64 ans = (rowMethods * colMethods % MOD) * chooseMethods % MOD;
            std::cout << ans << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    s.solve();

    return 0;
}