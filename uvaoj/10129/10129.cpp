#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::set<int> s;
        std::vector mat(26, std::vector<int>(26));
        std::string str;
        for (int i = 0; i < n; i++) {
            std::cin >> str;
            int u = str[0] - 'a', v = str.back() - 'a';
            s.insert(u);
            s.insert(v);
            mat[u][v] += 1;
        }

        int equalCnt = 0, notInDeg, notOutDeg;
        for (int i = 0; i < 26; i++) {
            if (!s.count(i)) { continue; }
            int inDeg = 0, outDeg = 0;
            for (int j = 0; j < 26; j++) { outDeg += mat[i][j]; }
            for (int j = 0; j < 26; j++) { inDeg += mat[j][i]; }
            if (inDeg == outDeg) { equalCnt += 1; }
            else {
                notInDeg = inDeg;
                notOutDeg = outDeg;
            }
        }

        auto isConnected = [&]() -> bool {
            int visited;
            std::vector<bool> vis;
            auto dfs = [&](auto self, int u) -> void {
                vis[u] = true;
                visited += 1;
                for (int i = 0; i < 26; i++) {
                    if (!vis[i] && mat[u][i]) { self(self, i); }
                }
            };

            for (int i = 0; i < 26; i++) {
                visited = 0;
                vis.assign(26, false);
                dfs(dfs, i);
                if (visited == s.size()) { return true; }
            }

            return false;
        };

        if (isConnected() && (equalCnt == s.size() || equalCnt == s.size() - 2 && std::abs(notOutDeg - notInDeg) == 1)) {
            std::cout << "Ordering is possible." << '\n';
            return;
        }
        std::cout << "The door cannot be opened." << '\n';
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
