#include <bits/stdc++.h>

void solve() {
    int N, H, W;
    std::cin >> N >> H >> W;

    std::vector<std::pair<int, int>> tiles(N);
    for (int i = 0; i < N; i++) {
        std::cin >> tiles[i].first >> tiles[i].second;
    }

    std::vector<bool> used(N, false);
    std::vector<std::vector<int>> filled(H, std::vector<int>(W, 0));

    auto fill = [&](int x, int y, int width, int height, int val) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                filled[x + i][y + j] = val;
            }
        }
    };

    auto canFill = [&](int x, int y, int width, int height) -> bool {
        if (x + height > H || y + width > W) {
            return false;
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (filled[x + i][y + j] == 1) {
                    return false;
                }
            }
        }

        return true;
    };

    std::function<bool(int, int)> dfs;
    dfs = [&](int x, int y) -> bool {
        if (y == W) { return dfs(x + 1, 0); }
        if (x == H) { return true; }
        if (filled[x][y] == 1) { return dfs(x, y + 1); }

        bool res = false;
        for (int i = 0; i < N; i++) {
            if (used[i]) {
                continue;
            }
            if (canFill(x, y, tiles[i].first, tiles[i].second)) {
                used[i] = true;
                fill(x, y, tiles[i].first, tiles[i].second, 1);
                res = dfs(x, y + tiles[i].first);
                fill(x, y, tiles[i].first, tiles[i].second, 0);
                used[i] = false;
            }
            if (canFill(x, y, tiles[i].second, tiles[i].first)) {
                used[i] = true;
                fill(x, y, tiles[i].second, tiles[i].first, 1);
                if (!res) {
                    res = dfs(x, y + tiles[i].second);
                }
                fill(x, y, tiles[i].second, tiles[i].first, 0);
                used[i] = false;
            }

            if (res) {
                break;
            }
        }

        return res;
    };

    if (dfs(0, 0)) {
        std::cout << "Yes" << '\n';
        return;
    }
    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
