#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::set<int> s;
    i64 ans = (i64) (K + 1) * K / 2;
    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if (num <= K && s.find(num) == s.end()) {
            ans -= num;
            s.insert(num);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
