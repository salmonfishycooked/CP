#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string encrypted, original;

    auto isTrue = [&]() -> bool {
        std::vector<int> cnt1(26), cnt2(26);
        for (auto ch : encrypted) {
            cnt1[ch - 'A'] += 1;
        }
        for (auto ch : original) {
            cnt2[ch - 'A'] += 1;
        }

        std::vector<int> c1, c2;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != 0) {
                c1.push_back(cnt1[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (cnt2[i] != 0) {
                c2.push_back(cnt2[i]);
            }
        }

        if (c1.size() != c2.size()) { return false; }

        std::sort(c1.begin(), c1.end());
        std::sort(c2.begin(), c2.end());
        for (int i = 0; i < c1.size(); i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }

        return true;
    };

    while ((std::cin >> encrypted) && (std::cin >> original)) {
        std::cout << (isTrue() ? "YES" : "NO") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
