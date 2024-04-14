#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string s;
    std::cin >> s;

    int cnt[101] = {0};

    std::map<char, int> m;
    for (auto ch : s) {
        m[ch] += 1;
    }

    for (auto [x, y] : m) {
        cnt[y] += 1;
    }

    for (int i = 1; i <= 100; i++) {
        if (cnt[i] != 0 && cnt[i] != 2) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
