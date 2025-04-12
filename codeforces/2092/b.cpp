#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::string a, b;
        std::cin >> a >> b;

        int ans = 1, zeros = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) { zeros += b[i] == '0'; }
            else { zeros -= a[i] == '1'; }
        }
        if (zeros < 0) { ans = 0; }

        zeros = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2) { zeros -= a[i] == '1'; }
            else { zeros += b[i] == '0'; }
        }
        if (zeros < 0) { ans = 0; }

        std::cout << (ans ? "YES" : "NO") << '\n';
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
