#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0;
    struct Node { int left, right, v; };

    int root, sz;
    std::vector<Node> tree;

    void init() {
        root = 1, sz = 1;
        tree.resize(2);
        tree[1] = {0, 0, -1};
    }

    int scanNodes() {
        int cnt = 0;
        std::string str;
        while (std::cin >> str && str != "()") {
            int v = 0, i;
            for (i = 1; str[i] != ','; i++) { v = v * 10 + str[i] - '0'; }

            int cur = root;
            for (i = i + 1; str[i] != ')'; i++) {
                if (str[i] == 'R') {
                    if (tree[cur].right == ROXY) {
                        tree[cur].right = tree.size();
                        tree.push_back({0, 0, -1});
                        sz += 1;
                    }
                    cur = tree[cur].right;
                } else {
                    if (tree[cur].left == ROXY) {
                        tree[cur].left = tree.size();
                        tree.push_back({0, 0, -1});
                        sz += 1;
                    }
                    cur = tree[cur].left;
                }
            }

            tree[cur].v = v;
            cnt += 1;
        }

        return cnt;
    }

    void solve() {
        while (true) {
            init();
            int cnt = scanNodes();
            if (cnt == 0) { break; }
            if (cnt != sz) {
                std::cout << "not complete" << '\n';
                continue;
            }

            std::queue<int> q;
            q.push(root);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                std::cout << tree[u].v;

                if (tree[u].left != ROXY) { q.push(tree[u].left); }
                if (tree[u].right != ROXY) { q.push(tree[u].right); }

                if (!q.empty()) { std::cout << ' '; }
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
