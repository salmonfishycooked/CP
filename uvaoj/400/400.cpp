#include <bits/stdc++.h>

using i64 = int64_t;

void solve(int n) {
    int mxLen = 0;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        mxLen = std::max(mxLen, (int) s[i].size());
    }

    std::sort(s.begin(), s.end());

    for (int i = 0; i < 60; i++) {
        std::cout << '-';
    }
    std::cout << '\n';

    auto print = [&](int pos, int len, char ch) {
        std::cout << s[pos];
        int fillCnt = len - s[pos].length();
        for (int i = 0; i < fillCnt; i++) {
            std::cout << ch;
        }
    };

    int cols = (60 - mxLen) / (mxLen + 2) + 1;
    int rows = (n - 1) / cols + 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int pos = i + j * rows;
            if (pos < n) {
                print(pos, j == (cols - 1) ? mxLen : (mxLen + 2), ' ');
            }
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n) {
        solve(n);
    }

    return 0;
}
