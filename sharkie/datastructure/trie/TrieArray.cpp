/**
 * Trie 前缀树（数组实现）
 * 与链表实现不同的是，不手动需要 DFS 来释放分散的内存，最后会自动回收栈内存，
 * 回收 std::vector 的效率远比 DFS 回收所有分散内存高。
 *
 * 方法说明：
 * 1. void insert(const std::string &word) 向 Trie 中插入字符串 word
 * 2. bool search(const std::string &word) 在 Trie 中搜索是否存在字符串 word，存在则返回 true，不存在则返回 false
 * 3. bool startsWith(const std::string &prefix) 在 Trie 中搜索是否存在单词拥有前缀 prefix
 * 4. int findNode(const std::string &word) 在 Trie 中查找单词 word 的终点 Node 的索引，若不存在该节点，返回 NONE
 *
 * 参数说明：
 * 1. NONE 若一个节点的儿子索引值等于 NONE（这里设置为 -1），则代表这个节点没有儿子
 *
 * Node 说明：
 * 1. children 是节点的儿子节点，从 'a' ~ 'z'，共 26 个字符
 * 2. passed 的值是有多少单词经过该节点
 * 3. exist 的值是有多少单词在这这个节点结尾
 */

#include <bits/stdc++.h>

class Trie {
public:
    class Node {
    public:
        std::vector<int> children;
        int passed, exist;

        explicit Node() : passed(0), exist(0) {
            children.assign(26, NONE);
        }
    };

    static constexpr int NONE = -1;
    std::vector<Node> tree;

    explicit Trie() {
        tree.emplace_back();
    }

    void insert(const std::string &word) {
        int cur = 0;
        for (auto ch : word) {
            tree[cur].passed += 1;
            if (tree[cur].children[ch - 'a'] == NONE) {
                tree.emplace_back();
                tree[cur].children[ch - 'a'] = tree.size() - 1;
            }
            cur = tree[cur].children[ch - 'a'];
        }
        tree[cur].passed += 1;
        tree[cur].exist += 1;
    }

    bool search(const std::string &word) {
        int cur = findNode(word);

        return cur != NONE && tree[cur].exist > 0;
    }

    bool startsWith(const std::string &prefix) {
        int cur = findNode(prefix);

        return cur != NONE && tree[cur].passed > 0;
    }

    int findNode(const std::string &word) {
        int cur = 0;
        for (auto ch : word) {
            if (tree[cur].children[ch - 'a'] == NONE) {
                return NONE;
            }
            cur = tree[cur].children[ch - 'a'];
        }

        return cur;
    }
};
