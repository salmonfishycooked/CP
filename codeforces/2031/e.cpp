#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0, ROOT = 1;
    struct Node { std::vector<int> children; };

    void solve() {
        int n;
        std::cin >> n;

        std::vector<Node> tree(n + 1);
        for (int i = 2, fa; i <= n; i++) {
            std::cin >> fa;
            tree[fa].children.push_back(i);
        }

        std::vector<int> f(n + 1);
        auto dfs = [&](auto self, int cur) -> void {
            std::priority_queue<int, std::vector<int>, std::greater<>> q;
            for (auto child : tree[cur].children) {
                self(self, child);
                q.push(f[child]);
            }
            if (q.empty()) { return; }
            if (q.size() == 1) {
                f[cur] = q.top() + 1;
                return;
            }

            while (q.size() > 2) {
                int v1 = q.top(); q.pop();
                int v2 = q.top(); q.pop();
                q.push(std::max(v1, v2) + 1);
            }
            q.pop();
            f[cur] = q.top() + 1;
        };
        dfs(dfs, ROOT);

        std::cout << f[ROOT] << '\n';
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
