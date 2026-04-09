#include <bits/stdc++.h>

using i64 = long long;

const i64 MOD = 998244353;

i64 f[2][5][5][5][5];

inline int getV(int pos,int idx) {
    static int odd[5] = {1, 3, 5, 7, 9};
    static int even[5] = {0, 2, 4, 6, 8};

    return (pos & 1) ? odd[idx] : even[idx];
}

class Solution {
public:
    void solve() {
        int n, m;
        std::cin >> n >> m;

        for (int d = 0; d < 5; ++d) {
            for (int c = 0; c < 5; ++c) {
                for (int b = 0; b < 5; ++b) {
                    for (int a = 0; a < 5; ++a) {
                        const i64 sum = getV(5, a) + getV(4, b) + getV(3, c) + getV(2, d);
                        for (int e = 0; e < 5; ++e) {
                            if (sum + getV(1, e) > m) { continue; }
                            f[0][a][b][c][d] += 1;
                        }
                    }
                }
            }
        }

        int cur = 0, prev = 1;
        for (int pos = 6; pos <= n; ++pos) {
            cur = cur ^ 1;
            prev = prev ^ 1;
            for (int a = 0; a < 5; ++a) {
                for (int b = 0; b < 5; ++b) {
                    for (int c = 0; c < 5; ++c) {
                        for (int d = 0; d < 5; ++d) {
                            f[cur][a][b][c][d] = 0;
                        }
                    }
                }
            }

            for (int a = 0; a < 5; ++a) {
                for (int b = 0; b < 5; ++b) {
                    for (int c = 0; c < 5; ++c) {
                        for (int d = 0; d < 5; ++d) {
                            const i64 sum = getV(pos, a) + getV(pos - 1, b) + getV(pos - 2, c) + getV(pos - 3, d);
                            for (int e = 0; e < 5; ++e) {
                                if (sum + getV(pos - 4, e) > m) { break; }
                                f[cur][a][b][c][d] += f[prev][b][c][d][e];
                                if (f[cur][a][b][c][d] >= MOD) { f[cur][a][b][c][d] -= MOD; }
                            }
                        }
                    }
                }
            }
        }

        i64 ans = 0;
        for (int a = 0; a < 5; ++a) {
            for (int b = 0; b < 5; ++b) {
                for (int c = 0; c < 5; ++c) {
                    for (int d = 0; d < 5; ++d) {
                        ans = (ans + f[cur][a][b][c][d]) % MOD;
                    }
                }
            }
        }

        std::cout << ans << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}