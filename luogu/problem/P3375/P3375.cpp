#include <bits/stdc++.h>

using i64 = int64_t;

std::vector<int> next;

std::vector<int> kmp(const std::string &str, const std::string &pat) {
    int n = (int) str.size(), m = (int) pat.size();

    next.resize(m);
    next[0] = 0;
    for (int i = 1; i < m; i++) {
        int j = next[i - 1];
        while (j > 0 && pat[j] != pat[i]) {
            j = next[j - 1];
        }

        if (pat[j] != pat[i]) {
            next[i] = 0;
            continue;
        }
        next[i] = j + 1;
    }

    std::vector<int> ans;
    for (int i = 0, j = 0; i < n; i++) {
        if (str[i] == pat[j]) {
            j += 1;
            if (j == m) {
                ans.push_back(i - m + 1);
                i = i - m + 1;
                j = 0;
            }
            continue;
        }

        while (j > 0 && str[i] != pat[j]) {
            j = next[j - 1];
        }
        if (str[i] == pat[j]) { j += 1; }
    }

    return ans;
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
