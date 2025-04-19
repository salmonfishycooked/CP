#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        std::string num;
        std::cin >> num;

        int n = (int) num.size(), ans = 0, i = n - 1;
        while (i >= 0 && num[i] == '0') { i -= 1; }
        ans += n - 1 - i;
        for (int j = 0; j < i; j++) { ans += (num[j] != '0'); }

        std::cout << ans << '\n';
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
