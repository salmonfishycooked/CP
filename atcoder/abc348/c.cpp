#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;

    int a, c;
    std::map<int, int> beans;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> c;
        if (beans.find(c) == beans.end()) {
            beans[c] = a;
            continue;
        }
        beans[c] = std::min(beans[c], a);
    }

    int curC, curA = 0;
    for (auto &[x, y] : beans) {
        if (y > curA) {
            curC = x;
            curA = y;
        }
    }

    std::cout << curA << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
