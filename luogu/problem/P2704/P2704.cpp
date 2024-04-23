/**
 * 洛谷P2704 [NOI2001] 炮兵阵地
 * 三进制轮廓线状态压缩 DP
 */
#include <bits/stdc++.h>

using i64 = int64_t;

char grid[100][10];
int f[10][59049];
int powThree[11];

class Base3 {
public:
    static int getPos(int msk, int pos) {
        return msk / powThree[pos] % 3;
    }

    static int addAtPos(int msk, int pos, int delta) {
        msk += delta * powThree[pos];

        return msk;
    }

    static int decreasePosIfValid(int msk, int pos, int num) {
        if (getPos(msk, pos) == 0) {
            return msk;
        }

        return addAtPos(msk, pos, -num);
    }

    static int setPosValid(int msk, int pos) {
        if (getPos(msk, pos) == 0) {
            return addAtPos(msk, pos, 1);
        }

        return msk;
    }
};

void solve() {
    int N, M;
    std::cin >> N >> M;

    powThree[0] = 1;
    for (int i = 1; i <= 10; i++) {
        powThree[i] = powThree[i - 1] * 3;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> grid[i][j];
        }
    }

    int ASet = powThree[M];
    for (int i = 0; i < ASet; i++) {
        f[0][i] = 0;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            for (int msk = 0; msk < ASet; msk++) {
                f[j][msk] = f[(j + 1) % M][Base3::decreasePosIfValid(msk, j, 1)];
                if (grid[i][j] == 'P' && Base3::getPos(msk, j) == 0) {
                    int nMsk = Base3::addAtPos(msk, j, 2);
                    if (j + 1 < M) {
                        nMsk = Base3::setPosValid(nMsk, j + 1);
                    }
                    if (j + 2 < M) {
                        nMsk = Base3::setPosValid(nMsk, j + 2);
                    }
                    f[j][msk] = std::max(f[j][msk], f[(j + 1) % M][nMsk] + 1);
                }
            }
        }
    }

    std::cout << f[0][0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
