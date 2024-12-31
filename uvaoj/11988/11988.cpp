#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string str;
    while (std::cin >> str) {
        std::list<char> list;
        auto insertPos = list.begin();
        for (auto &ch : str) {
            if (ch == '[') { insertPos = list.begin(); continue; }
            if (ch == ']') { insertPos = list.end(); continue; }
            insertPos = list.insert(insertPos, ch);
            ++insertPos;
        }

        for (auto &ch : list) {
            std::cout << ch;
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
