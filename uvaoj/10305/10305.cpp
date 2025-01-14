#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, m;
        while (std::cin >> n >> m) {
            if (n == 0) { break; }

            std::vector<std::vector<int>> adj(n + 1);
            std::vector<int> inDeg(n + 1);
            for (int i = 0, u, v; i < m; i++) {
                std::cin >> u >> v;
                adj[u].push_back(v);
                inDeg[v] += 1;
            }

            std::queue<int> q;
            for (int i = 1; i <= n; i++) {
                if (inDeg[i] == 0) { q.push(i); }
            }

            while (!q.empty()) {
                int u = q.front(); q.pop();
                std::cout << u << ' ';
                for (auto to : adj[u]) {
                    inDeg[to] -= 1;;
                    if (inDeg[to] == 0) { q.push(to); }
                }
            }
            std::cout << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
