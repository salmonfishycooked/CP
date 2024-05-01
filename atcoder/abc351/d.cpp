#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> grid(N);
    for (auto &str : grid) {
        std::cin >> str;
    }

    std::vector visited(N, std::vector<bool>(M));
    auto bfs = [&](int i, int j) -> int {
        int ret = 1;
        std::queue<std::pair<int, int>> q;
        std::set<std::pair<int, int>> borderV;
        q.emplace(i, j);
        visited[i][j] = true;
        std::vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            bool canMove = true;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (grid[nx][ny] == '#') {
                    canMove = false;
                    break;
                }
            }
            if (!canMove) {
                grid[x][y] = '%';
                ret -= 1;
                borderV.insert({x, y});
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (grid[nx][ny] == '%') {
                    borderV.insert({nx, ny});
                    continue;
                }
                if (grid[nx][ny] != '#' && !visited[nx][ny]) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                    ret += 1;
                }
            }
        }

        return ret + borderV.size();
    };

    int ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != '#') {
                ans = std::max(ans, bfs(i, j));
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
