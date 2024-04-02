#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, C;
    std::cin >> a >> b >> C;

    int cntC = 0;
    std::vector<bool> bits(63, false);
    for (int i = 0; i < 63; i++) {
        if (C & (1LL << i)) {
            cntC += 1;
            bits[i] = true;
        }
    }
    if (a + b < cntC || cntC < std::abs(a - b) || (cntC - std::abs(a - b)) % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    i64 X = 0, Y = 0;
    int needX = std::abs(a - b) + ((cntC - std::abs(a - b)) / 2);
    for (int i = 0; i < 63; i++) {
        if (!bits[i]) { continue; }
        if (needX) {
            X |= (1LL << i);
            needX--;
            continue;
        }
        Y |= (1LL << i);
    }

    int remain = std::min(a, b) - ((cntC - std::abs(a - b)) / 2);
    for (int i = 0; i < 63; i++) {
        if (remain == 0) { break; }
        if (!bits[i]) {
            X |= (1LL << i);
            Y |= (1LL << i);
            remain -= 1;
        }
    }

    if (remain == -1 || X > (1LL << 60) || Y > (1LL << 60)) {
        std::cout << -1 << '\n';
        return;
    }

    if (a < b) {
        std::swap(X, Y);
    }
    std::cout << X << ' ' << Y << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
