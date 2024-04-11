/**
 * 洛谷 P1541 [NOIP2010 提高组] 乌龟棋
 * 注意下面代码中，决定某个子问题的状态选用的是 f[t1][t2][t3][t4] 而不是 f[N][t1][t2][t3][t4]
 * 直接开 f[N][t1][t2][t3][t4] 会内存超限
 * 由于状态 N 代表当前在乌龟在哪个格子，可以直接由打出了几张牌来确定 N，所以 N 可以 t1, t2, t3, t4 表达出来
 */
#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> score(N);
    for (int i = 0; i < N; i++) {
        std::cin >> score[i];
    }

    std::vector<int> type(4);
    for (int i = 0, tp; i < M; i++) {
        std::cin >> tp;
        tp -= 1;
        type[tp] += 1;
    }

    std::vector f(std::vector(type[0] + 1, std::vector(type[1] + 1, std::vector(type[2] + 1, std::vector<int>(type[3] + 1, -1)))));
    auto dfs = [&](auto self, int t1, int t2, int t3, int t4) -> int {
        int curN = (type[0] - t1) + (type[1] - t2) * 2 + (type[2] - t3) * 3 + (type[3] - t4) * 4;
        if (curN >= N) { return 0; }

        int &p = f[t1][t2][t3][t4];
        if (p != -1) { return p; }

        int res = 0;
        if (t1 > 0) {
            res = std::max(res, self(self, t1 - 1, t2, t3, t4));
        }
        if (t2 > 0) {
            res = std::max(res, self(self, t1, t2 - 1, t3, t4));
        }
        if (t3 > 0) {
            res = std::max(res, self(self, t1, t2, t3 - 1, t4));
        }
        if (t4 > 0) {
            res = std::max(res, self(self, t1, t2, t3, t4 - 1));
        }

        return p = res + score[curN];
    };

    std::cout << dfs(dfs, type[0], type[1], type[2], type[3]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
