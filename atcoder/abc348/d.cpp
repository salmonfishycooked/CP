#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int H, W;
    std::cin >> H >> W;

    std::pair<int, int> start, goal;
    std::vector A(H + 1, std::vector<char>(W + 1));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            std::cin >> A[i][j];
            switch (A[i][j]) {
                case 'S': start = {i, j}; break;
                case 'T': goal = {i, j}; break;
            }
        }
    }

    std::vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    auto bfs = [&](std::pair<int, int> source) -> std::vector<std::vector<int>> {
        std::vector dis(H + 1, std::vector(W + 1, -1));
        dis[source.first][source.second] = 0;
        std::vector vis(H + 1, std::vector(W + 1, false));
        std::queue<std::pair<int, int>> q;
        q.push(source);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx <= 0 || nx > H || ny <= 0 || ny > W) { continue; }
                if (A[nx][ny] == '#' || vis[nx][ny]) { continue; }
                q.emplace(nx, ny);
                vis[nx][ny] = true;
                dis[nx][ny] = dis[x][y] + 1;
            }
        }

        return dis;
    };

    int N;
    std::cin >> N;
    std::vector<std::tuple<int, int, int>> med(N);
    for (auto &[x, y, z] : med) {
        std::cin >> x >> y >> z;
    }

    std::queue<int> q;
    std::vector<bool> visMed(N);
    for (int i = 0; i < N; i++) {
        auto [x, y, z] = med[i];
        if (start.first == x && start.second == y) {
            visMed[i] = true;
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        auto [x, y, e] = med[q.front()];
        q.pop();
        std::vector dis = bfs({x, y});
        if (dis[goal.first][goal.second] <= e && dis[goal.first][goal.second] != -1) {
            std::cout << "Yes" << '\n';
            return;
        }
        for (int i = 0; i < N; i++) {
            auto [x1, y1, e1] = med[i];
            if (visMed[i] || dis[x1][y1] > e || dis[x1][y1] == -1) { continue; }
            q.push(i);
            visMed[i] = true;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
