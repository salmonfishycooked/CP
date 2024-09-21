#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> w(n), h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> h[i];
    }

    std::vector f1(n, std::vector<int>(201, -1));
    for (int i = 0; i < n; i++) {
        f1[i][0] = 0;
        int mnEdge = std::min(w[i], h[i]), mxEdge = std::max(w[i], h[i]);
        for (int j = 1; j <= 200; j++) {
            if (mnEdge == 0) { break; }

            f1[i][j] = f1[i][j - 1] + mnEdge;
            mxEdge -= 1;
            if (mxEdge < mnEdge) {
                std::swap(mxEdge, mnEdge);
            }
        }
        f1[i][w[i] + h[i]] = f1[i][w[i] + h[i] - 1];
    }

    std::vector f2(n + 1, std::vector<int>(k + 1, INT_MAX / 2));
    f2[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int score = 0; score <= k; score++) {
            for (int curScore = 0; curScore <= score; curScore++) {
                if (f1[i - 1][curScore] == -1) { break; }
                f2[i][score] = std::min(f2[i][score], f2[i - 1][score - curScore] + f1[i - 1][curScore]);
            }
        }
    }

    std::cout << (f2[n][k] == INT_MAX / 2 ? -1 : f2[n][k]) << '\n';
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
