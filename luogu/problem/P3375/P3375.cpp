#include <bits/stdc++.h>

using i64 = int64_t;

std::vector<int> next;

std::vector<int> kmp(const std::string &s1, const std::string &s2) {
    int n = s1.size(), m = s2.size();

    next.resize(m);
    for (int i = 1; i < m; i++) {
        int j = next[i - 1];
        while (j > 0 && s2[i] != s2[j]) {
            j = next[j - 1];
        }

        if (j == 0 && s2[i] != s2[0]) {
            next[i] = 0;
            continue;
        }
        next[i] = j + 1;
    }

    std::vector<int> ret;
    for (int i = 0, j = 0; i < n; i++) {
        if (s1[i] == s2[j]) {
            j += 1;
            if (j == m) {
                ret.push_back(i - m + 1);
                i = i - m + 1;
                j = 0;
            }
            continue;
        }

        while (j > 0 && s1[i] != s2[j]) {
            j = next[j - 1];
        }
        if (s1[i] == s2[j]) { j += 1; }
    }

    return ret;
}

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    for (auto pos : kmp(s1, s2)) {
        std::cout << pos + 1 << '\n';
    }

    for (auto v : next) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
