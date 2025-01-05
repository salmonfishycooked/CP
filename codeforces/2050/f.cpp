#include <bits/stdc++.h>

using i64 = long long;

class SparseTable {
public:
    int n;
    std::vector<std::vector<int>> f;

    explicit SparseTable(std::vector<int> &arr) {
        n = (int) arr.size();
        if (n == 0) { return; }

        int k = (int) std::log2(n);
        f.assign(k + 1, std::vector<int>(n));
        f[0] = arr;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                f[i][j] = std::gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int from, int to) {
        int k = (int) std::log2(to - from + 1);
        return std::gcd(f[k][from], f[k][to - (1 << k) + 1]);
    }
};


class Solution {
public:
    void solve() {
        int n, q;
        std::cin >> n >> q;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        std::vector<int> b(n - 1);
        for (int i = 0; i < n - 1; i++) { b[i] = std::abs(a[i + 1] - a[i]); }

        SparseTable st(b);
        for (int l, r; q; q--) {
            std::cin >> l >> r;
            l -= 1; r -= 1;
            int ans;
            if (l == r) { ans = 0; }
            else { ans = st.query(l, r - 1); }

            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
