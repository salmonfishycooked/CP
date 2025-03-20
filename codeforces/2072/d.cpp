#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        int mx = *std::max_element(a.begin(), a.end());
        std::vector lower(n + 2, std::array<int, 2000>{0});
        std::vector greater(n + 2, std::array<int, 2000>{0});
        for (int i = n; i >= 1; i--) {
            for (int num = 1; num <= mx; num++) {
                lower[i][num] = lower[i + 1][num] + (a[i - 1] < num);
                greater[i][num] = greater[i + 1][num] + (a[i - 1] > num);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) { cnt += lower[i][a[i - 1]]; }

        int ans = cnt, ansL = 1, ansR = 1;
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                int curV = cnt + greater[l + 1][a[l - 1]] - greater[r + 1][a[l - 1]] + lower[r + 1][a[l - 1]] - lower[l + 1][a[l - 1]];
                if (curV < ans) {
                    ansL = l;
                    ansR = r;
                    ans = curV;
                }
            }
        }

        std::cout << ansL << ' ' << ansR << '\n';
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
