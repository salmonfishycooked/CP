#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            std::cout << "x";
            continue;
        }
        std::cout << "o";
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
