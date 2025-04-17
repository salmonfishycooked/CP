#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, st, en;
        std::cin >> n >> st >> en;

        std::vector<std::vector<int>> tree(n + 1);
        for (int i = 1, u, v; i < n; i++) {
            std::cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        std::vector<int> seq = {en};
        std::queue<int> q;
        std::vector<bool> vis(n + 1);
        q.push(en);
        vis[en] = true;
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                for (auto child : tree[u]) {
                    if (vis[child]) { continue; }
                    vis[child] = true;
                    seq.push_back(child);
                    q.push(child);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) { std::cout << seq[i] << ' '; }
        std::cout << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
