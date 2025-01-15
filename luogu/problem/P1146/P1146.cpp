#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::cout << n << '\n';

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) { a[j] = !a[j];; }
                std::cout << a[j];
            }
            std::cout << '\n';
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
