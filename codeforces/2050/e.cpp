#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        std::string a, b, c;
        std::cin >> a >> b >> c;
        int n = (int) a.length(), m = (int) b.length();

        std::vector<int> f(m + 1, INT_MAX / 2);
        f[m] = 0;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i < n) { f[j] = f[j] + (a[i] != c[i + j]); }
                if (j < m) { f[j] = std::min(f[j], f[j + 1] + (b[j] != c[i + j])); }
            }
        }

        std::cout << f[0] << '\n';
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
