/**
 * Trie 前缀树（链表实现）
 * 注意：最后需要释放申请出来的内存（会 DFS 遍历树，消耗大量时间），不然会内存泄漏，测试多个样例的时候可能会爆内存
 * 如果不需要需要开启释放内存，把下面代码的析构函数注释掉即可。
 *
 * 方法说明：
 * 1. void insert(const std::string &word) 向 Trie 中插入字符串 word
 * 2. bool search(const std::string &word) 在 Trie 中搜索是否存在字符串 word，存在则返回 true，不存在则返回 false
 * 3. bool startsWith(const std::string &prefix) 在 Trie 中搜索是否存在单词拥有前缀 prefix
 * 4. Node *findNode(const std::string &word) 在 Trie 中查找单词 word 的终点 Node，若不存在该节点，返回 nullptr
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
        std::vector<Node*> children;
        int passed, exist;

        explicit Node() : passed(0), exist(0) {
            children.resize(26);
        }
    };

    Node *head;

    explicit Trie() : head(new Node()) {}

    ~Trie() {
        std::function<void(Node*)> releaseDfs;
        releaseDfs = [&](Node *root) {
            if (root == nullptr) { return; }
            for (int i = 0; i < 26; i++) {
                releaseDfs(root->children[i]);
            }
            delete root;
        };
        releaseDfs(head);
    }

    void insert(const std::string &word) {
        Node *cur = head;
        for (auto ch : word) {
            cur->passed += 1;
            if (cur->children[ch - 'a'] == nullptr) {
                cur->children[ch - 'a'] = new Node();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->passed += 1;
        cur->exist += 1;
    }

    bool search(const std::string &word) {
        Node *target = findNode(word);

        return target != nullptr && target->exist > 0;
    }

    bool startsWith(const std::string &prefix) {
        Node *target = findNode(prefix);

        return target != nullptr && target->passed > 0;
    }

    Node *findNode(const std::string &word) {
        Node *cur = head;
        for (auto ch : word) {
            if (cur->children[ch - 'a'] == nullptr) {
                return nullptr;
            }
            cur = cur->children[ch - 'a'];
        }

        return cur;
    }
};
