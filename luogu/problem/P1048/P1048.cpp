#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int T, M;
    std::cin >> T >> M;

    std::vector<int> times(M), values(M);
    for (int i = 0; i < M; i++) {
        std::cin >> times[i] >> values[i];
    }

    std::vector<int> f(T + 1);
    for (int i = 1; i <= M; i++) {
        for (int j = T; j >= times[i - 1]; j--) {
            f[j] = std::max(f[j], f[j - times[i - 1]] + values[i - 1]);
        }
    }

    std::cout << f[T] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
