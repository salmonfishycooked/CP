#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, k, m;
    while (std::cin >> N >> k >> m && N != 0) {
        std::vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) { a[i] = i; }

        auto pickOne = [&](int from, int delta, int cnt) -> int {
            while (cnt) {
                cnt -= (a[from] != 0);
                if (cnt == 0) { break; }
                from = (from + delta + N + 1) % (N + 1);
            }

            return from;
        };

        int remain = N, p1 = 1, p2 = N;
        while (remain) {
            p1 = pickOne(p1, 1, k), p2 = pickOne(p2, -1, m);
            std::cout << std::setw(3) << a[p1];
            remain -= 1;
            if (p1 != p2) {
                std::cout << std::setw(3) << a[p2];
                remain -= 1;
            }
            a[p1] = a[p2] = 0;
            if (remain) { std::cout << ','; }
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
