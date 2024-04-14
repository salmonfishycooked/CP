#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string S, T;
    std::cin >> S >> T;

    for (int i = 0; i < 3; i++) {
        T[i] += 32;
    }

    int ptr = 0;
    for (auto ch : S) {
        if (T[ptr] == ch) {
            ptr += 1;
        }
        if (ptr == 3) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    if (ptr == 2 && T[2] == 'x') {
        std::cout << "Yes" << '\n';
        return;
    }
    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
