#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0, ROOT = 1;

    struct Node {
        char type;
        std::vector<int> children;
    };

    void buildTree(std::vector<Node> &tree, const std::string &str) {
        int ptr = 0;
        auto build = [&](auto self) -> int {
            int me = (int) tree.size();
            tree.push_back({str[ptr++], {}});
            if (tree[me].type == 'p') {
                for (int i = 0; i < 4; i++) {
                    int child = self(self);
                    tree[me].children.push_back(child);
                }
            }

            return me;
        };
        build(build);
    }

    int getDepth(std::vector<Node> &tree) {
        auto calc = [&](auto self, int cur) -> int {
            int res = 0;
            for (auto child : tree[cur].children) {
                res = std::max(res, self(self, child));
            }

            return res + 1;
        };

        return calc(calc, ROOT);
    }

    void fillTree(std::vector<Node> &tree, int depth) {
        auto fill = [&](auto self, int cur, int curDepth) -> void {
            if (curDepth == depth) { return; }

            if (tree[cur].children.empty()) {
                for (int i = 0; i < 4; i++) {
                    int id = (int) tree.size();
                    tree.push_back({tree[cur].type, {}});
                    tree[cur].children.push_back(id);
                    self(self, id, curDepth + 1);
                }
            } else {
                for (auto child : tree[cur].children) {
                    self(self, child, curDepth + 1);
                }
            }
        };
        fill(fill, ROOT, 1);
    }

    std::vector<int> getLevelNodeId(std::vector<Node> &tree, int depth) {
        std::queue<int> q;
        q.push(ROOT);
        for (int d = 1; !q.empty(); d++) {
            std::vector<int> ids;
            for (; !q.empty(); q.pop()) { ids.push_back(q.front()); }
            if (d == depth) { return ids; }

            for (auto cur : ids) {
                for (auto child : tree[cur].children) { q.push(child); }
            }
        }

        return {};
    }

    void solve() {
        std::vector<Node> tree1(1), tree2(1);
        std::string str;
        std::cin >> str;
        buildTree(tree1, str);
        std::cin >> str;
        buildTree(tree2, str);

        int mxDepth = std::max(getDepth(tree1), getDepth(tree2)), len = 32 / std::pow(2, mxDepth - 1);
        fillTree(tree1, mxDepth);
        fillTree(tree2, mxDepth);

        int ans = 0;
        auto level1 = getLevelNodeId(tree1, mxDepth);
        auto level2 = getLevelNodeId(tree2, mxDepth);
        for (int i = level1.size() - 1; i >= 0; i--) {
            if (tree1[level1[i]].type == 'f' || tree2[level2[i]].type == 'f') { ans += len * len; }
        }

        std::cout << "There are " << ans << " black pixels." << '\n';
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
