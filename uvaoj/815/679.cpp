#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int D, I;
    std::cin >> D >> I;

    int pos = 1, ballCnt = I;
    for (int i = 1; i < D; i++) {
        pos *= 2;
        if (ballCnt % 2) { ballCnt = (ballCnt + 1) / 2; }
        else {
            pos += 1;
            ballCnt /= 2;
        }
    }

    std::cout << pos << '\n';
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
