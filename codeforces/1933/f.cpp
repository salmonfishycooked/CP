#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> cell(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> cell[i][j];
        }
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (dist[(x + 2) % n][y] == -1 && cell[(x + 1) % n][y] != 1 && cell[(x + 2) % n][y] != 1) {
            dist[(x + 2) % n][y] = dist[x][y] + 1;
            q.emplace((x + 2) % n, y);
        }
        if (y + 1 < m && dist[(x + 1) % n][y + 1] == -1 && cell[(x + 1) % n][y + 1] != 1) {
            dist[(x + 1) % n][y + 1] = dist[x][y] + 1;
            q.emplace((x + 1) % n, y + 1);
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (dist[i][m - 1] == -1) {
            continue;
        }
        int finalPos = (n - 1 + dist[i][m - 1]) % n;
        ans = std::min(ans, dist[i][m - 1] + std::min((i - finalPos + n) % n, (finalPos - i + n) % n));
    }
    if (ans == 0x3f3f3f3f) {
        ans = -1;
    }
    std::cout << ans << '\n';
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
