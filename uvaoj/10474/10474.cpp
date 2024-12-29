#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    for (int round = 1; ; round++) {
        int N, Q;
        std::cin >> N >> Q;

        if (N == 0 && Q == 0) { break; }

        std::vector<int> marbles(N);
        for (int i = 0; i < N; i++) {
            std::cin >> marbles[i];
        }

        std::sort(marbles.begin(), marbles.end());

        std::cout << "CASE# " << round << ':' << '\n';
        for (int v; Q; Q--) {
            std::cin >> v;
            auto it = std::lower_bound(marbles.begin(), marbles.end(), v);
            if (it == marbles.end() || *it != v) { std::cout << v << " not found" << '\n'; }
            else { std::cout << v << " found at " << (it - marbles.begin() + 1) << '\n'; }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
