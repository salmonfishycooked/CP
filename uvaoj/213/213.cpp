#include <bits/stdc++.h>

using i64 = long long;

int readChar() {
    while (1) {
        int ch = std::cin.get();
        if (ch != '\n' && ch != '\r') { return ch; }
    }
}

int readBin(int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = (res << 1) + (readChar() - '0');
    }

    return res;
}

void solve() {
    std::string pat;
    while (std::getline(std::cin, pat)) {
        std::vector m(8, std::vector<char>(128));
        for (int i = 0, len = 1, v = 0; i < pat.length(); i++, v++) {
            if (v == (1 << len) - 1) {
                len += 1;
                v = 0;
            }
            m[len][v] = pat[i];
        }

        int len;
        while ((len = readBin(3)) != 0) {
            int boundV = (1 << len) - 1, code;
            while ((code = readBin(len)) != boundV) {
                std::cout << m[len][code];
            }
        }
        std::cout << '\n';
        std::getline(std::cin, pat);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
