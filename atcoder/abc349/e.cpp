#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int A[9];
    i64 s = 0;
    for (int i = 0; i < 9; i++) {
        std::cin >> A[i];
        s += A[i];
    }

    auto checkIfWin = [](const std::vector<int> &grid) -> bool {
        for (int i = 0; i <= 2; i++) {
            if (grid[i] != 2 && grid[i + 3] == grid[i] && grid[i + 6] == grid[i]) {
                return true;
            }
        }
        for (int i = 0; i <= 6; i += 3) {
            if (grid[i] != 2 && grid[i + 1] == grid[i] && grid[i + 2] == grid[i]) {
                return true;
            }
        }
        if ((grid[0] != 2 && grid[4] == grid[0] && grid[8] == grid[0]) ||
            (grid[2] != 2 && grid[4] == grid[2] && grid[6] == grid[2])) {
            return true;
        }

        return false;
    };

    auto dfs = [&](auto self, std::vector<int> &grid, int who, i64 sum) -> i64 {
        i64 res = LONG_LONG_MIN / 2;
        if (checkIfWin(grid)) { return res; }

        bool end = true;
        for (int i = 0; i < 9; i++) {
            if (grid[i] != 2) { continue; }
            end = false;
            grid[i] = who;
            res = std::max(res, sum - self(self, grid, who ^ 1, sum - A[i]));
            grid[i] = 2;
        }

        if (end) { return 0; }

        return res;
    };

    std::vector<int> grid(9, 2);
    i64 me = dfs(dfs, grid, 0, s);
    if (me > s - me) {
        std::cout << "Takahashi" << '\n';
        return;
    }
    std::cout << "Aoki" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
