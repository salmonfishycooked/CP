#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        int mx = 0;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
        }

        std::vector<int> preMax(n, 0), sufMin(n, n - 1);
        for (int i = 1; i < n; i++) {
            preMax[i] = preMax[i - 1];
            if (a[i] > a[preMax[i]]) { preMax[i] = i; }
        }
        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = sufMin[i + 1];
            if (a[i] < a[sufMin[i]]) { sufMin[i] = i; }
        }

        std::vector<int> f(n);
        f[n - 1] = mx;
        for (int i = n - 2; i >= 0; i--) {
            int rightMin = sufMin[i + 1];
            int leftMax = preMax[i];
            f[i] = a[leftMax];
            if (a[leftMax] > a[rightMin]) { f[i] = f[rightMin]; }
        }

        for (int i = 0; i < n; i++) { std::cout << f[i] << ' '; }
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
