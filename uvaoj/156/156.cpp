#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::vector<std::string> strs;
    for (std::string str;;) {
        std::cin >> str;
        if (str == "#") { break; }
        strs.push_back(str);
    }

    auto lowerStr = [&](const std::string &str) {
        std::string res;
        for (auto &ch : str) {
            res.push_back(std::tolower(ch));
        }

        return res;
    };

    std::map<std::string, int> cnt;
    for (auto &str : strs) {
        std::string loweredStr = lowerStr(str);
        std::sort(loweredStr.begin(), loweredStr.end());
        cnt[loweredStr] += 1;
    }

    std::vector<std::string> ans;
    for (auto &str : strs) {
        std::string loweredStr = lowerStr(str);
        std::sort(loweredStr.begin(), loweredStr.end());
        if (cnt[loweredStr] == 1) { ans.push_back(str); }
    }

    std::sort(ans.begin(), ans.end());
    for (auto &str : ans) {
        std::cout << str << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
