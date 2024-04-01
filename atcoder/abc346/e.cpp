#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int H, W, M;
    std::cin >> H >> W >> M;

    std::vector<int> T(M), A(M), X(M);
    for (int i = 0; i < M; i++) {
        std::cin >> T[i] >> A[i] >> X[i];
        A[i]--;
    }

    std::map<int, i64> m;
    std::vector<bool> printedR(H), printedC(W);
    int remainR = H, remainC = W;
    for (int i = M - 1; i >= 0; i--) {
        if (T[i] == 1 && !printedR[A[i]]) {
            m[X[i]] += remainC;
            printedR[A[i]] = true;
            remainR -= 1;
        } else if (T[i] == 2 && !printedC[A[i]]) {
            m[X[i]] += remainR;
            printedC[A[i]] = true;
            remainC -= 1;
        }

        if (remainR == 0 || remainC == 0) {
            break;
        }
    }

    if (remainR > 0 && remainC > 0) {
        m[0] += (i64) remainR * remainC;
    }

    std::cout << m.size() << '\n';
    for (auto &[x, y] : m) {
        std::cout << x << ' ' << y << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
