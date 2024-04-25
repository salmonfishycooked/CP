#include <bits/stdc++.h>

using i64 = int64_t;

int powThree[10];
i64 f[9][82][19683];

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

    static int setPosToX(int msk, int pos, int x) {
        return addAtPos(msk, pos, x - getPos(msk, pos));
    }
};

void solve() {
    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < powThree[N]; i++) {
        f[0][0][i] = 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            for (int k = 0; k <= K; k++) {
                for (int msk = 0; msk < powThree[N]; msk++) {
                    if (k == 0) {
                        f[j][k][msk] = 1;
                        continue;
                    }

                    f[j][k][msk] = f[(j + 1) % N][k][Base3::decreasePosIfValid(msk, j, 1)];
                    if (!Base3::getPos(msk, j)) {
                        int nMsk = Base3::addAtPos(msk, j, 1);
                        if (j - 1 >= 0) {
                            nMsk = Base3::setPosToX(nMsk, j - 1, 1);
                        }
                        if (j + 1 < N) {
                            nMsk = Base3::setPosToX(nMsk, j + 1, 2);
                        }
                        f[j][k][msk] += f[(j + 1) % N][k - 1][nMsk];
                    }
                }
            }
        }
    }

    std::cout << f[0][K][0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    powThree[0] = 1;
    for (int i = 1; i < 10; i++) {
        powThree[i] = powThree[i - 1] * 3;
    }

    solve();

    return 0;
}
