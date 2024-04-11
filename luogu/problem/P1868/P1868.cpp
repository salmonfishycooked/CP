#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> a(N);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }

    std::sort(a.begin(), a.end());

    auto find = [&](int v) -> int {
        int l = -1, r = N;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (a[mid].first > v) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    };

    std::vector<i64> f(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        int nextIdx = find(a[i].second);
        f[i] = std::max(f[i + 1], f[nextIdx] + a[i].second - a[i].first + 1);
    }

    std::cout << f[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
