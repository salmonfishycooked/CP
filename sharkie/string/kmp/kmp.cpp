#include <bits/stdc++.h>

int kmp(const std::string &str, const std::string &pat) {
    int n = str.size(), m = pat.size();

    std::vector<int> next(m);
    for (int i = 1; i < m; i++) {
        int j = next[i - 1];
        while (j > 0 && pat[i] != pat[j]) {
            j = next[j - 1];
        }

        if (pat[i] != pat[0]) {
            next[i] = 0;
            continue;
        }
        next[i] = j + 1;
    }

    for (int i = 0, j = 0; i < n; i++) {
        if (str[i] == pat[j]) {
            j += 1;
            if (j == m) {
                return i - m + 1;
            }
            continue;
        }

        while (j > 0 && str[i] != pat[j]) {
            j = next[j - 1];
        }
        if (str[i] == pat[j]) { j += 1; }
    }

    return -1;
}
