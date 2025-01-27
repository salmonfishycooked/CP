#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) { std::cin >> a[i]; }

        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                flag = false;
                break;
            }
            a[i + 1] -= a[i];
        }

        std::cout << (flag ? "YES" : "NO") << '\n';
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
