#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        std::string s;
        std::cin >> s;

        std::list<char> list;
        for (auto &ch : s) { list.push_back(ch); }

        std::string ans;
        while (!list.empty()) {
            char base = 0, mx;
            std::list<char>::iterator ptr;
            int i = 0;
            for (auto it = list.begin(); it != list.end() && base <= '9'; ++it, ++base, ++i) {
                if (*it > base) {
                    base = *it;
                    ptr = it;
                    mx = *it - i;
                }
            }
            ans.push_back(mx);
            list.erase(ptr);
        }

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
