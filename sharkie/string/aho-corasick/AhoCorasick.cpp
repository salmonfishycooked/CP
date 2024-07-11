/**
 * AC自动机 (Aho-Corasick Automaton)
 *
 * 方法说明：
 * 1. int insert(const std::string &pat) 插入一个模式串到 Trie 树中，并返回其终点的节点编号。
 * 2. void build() 根据已插入的模式串构建AC自动机。
 *
 * 参数说明：
 * 1. ROOT 代表根结点的编号。
 * 2. NONE 代表空节点。
 * 3. std::vector<int> bfsOrder 里面是 Trie 树中所有节点的 BFS 序。
 *
 * 例题：洛谷P3966: https://www.luogu.com.cn/problem/P3966
 */

#include <bits/stdc++.h>

template <int sigma = 26, char start = 'a'>
class AhoCorasick {
public:
    struct Node {
        std::array<int, sigma> children;
        std::array<int, sigma> go;
        int fail;

        Node() : fail(ROOT) {
            children.fill(NONE);
        }
    };

    std::vector<Node> nodes;
    static constexpr int ROOT = 0;
    static constexpr int NONE = -1;

    std::vector<int> bfsOrder;

    explicit AhoCorasick() {
        nodes.emplace_back();
    }

    int insert(const std::string &pat) {
        int cur = ROOT;
        for (auto ch : pat) {
            int next = ch - start;
            if (nodes[cur].children[next] == NONE) {
                nodes[cur].children[next] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[next];
        }

        return cur;
    }

    void build() {
        bfsOrder.push_back(ROOT);
        for (int ptr = 0; ptr < bfsOrder.size(); ptr++) {
            int cur = bfsOrder[ptr];
            for (int i = 0; i < sigma; i++) {
                if (nodes[cur].children[i] != NONE) {
                    nodes[cur].go[i] = nodes[cur].children[i];
                    if (cur == ROOT) {
                        nodes[nodes[cur].children[i]].fail = ROOT;
                    } else {
                        nodes[nodes[cur].children[i]].fail = nodes[nodes[cur].fail].go[i];
                    }

                    bfsOrder.push_back(nodes[cur].children[i]);
                } else {
                    if (cur == ROOT) {
                        nodes[cur].go[i] = ROOT;
                    } else {
                        nodes[cur].go[i] = nodes[nodes[cur].fail].go[i];
                    }
                }
            }
        }
    }
};
