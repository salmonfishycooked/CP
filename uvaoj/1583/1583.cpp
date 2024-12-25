#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;

    auto cal = [&](int num) -> int {
        int res = num;
        while (num) {
            res += num % 10;
            num /= 10;
        }

        return res;
    };

    int ans = 0;
    for (int i = std::max(1, N - 54); i < N; i++) {
        if (cal(i) == N) {
            ans = i;
            break;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
