#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int ch, flag = 1;
    while ((ch = getchar()) != EOF) {
        if (ch == '"') {
            std::cout << (flag ? "``" : "''");
            flag = !flag;
            continue;
        }
        std::cout << (char) ch;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
