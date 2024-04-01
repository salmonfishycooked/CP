#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    std::sort(X.begin(), X.end());

    auto check = [&](int dist) -> bool {
        int prev = 0, cur = 1;
        for (int i = 1; i < C; i++) {
            while (cur < N && X[cur] - X[prev] < dist) {
                cur += 1;
            }
            if (cur == N) {
                return false;
            }
            prev = cur;
        }

        return true;
    };

    int l = 0, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    std::cout << l << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
