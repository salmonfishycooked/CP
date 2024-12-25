#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string str = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int ch;
    while ((ch = getchar()) != EOF) {
        int i = 1;
        for (; str[i] && str[i] != ch; i++) {}
        if (str[i]) {
            std::cout << str[i - 1];
        } else {
            std::cout << (char) ch;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
