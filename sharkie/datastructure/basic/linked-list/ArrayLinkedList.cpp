/**
* ArrayLinkedList - 链表（数组实现）
 * 带虚拟头尾节点。
 *
 * 公有方法说明：
 * 1. int insert(int id, Info &info)，在编号为id的节点处插入一个新节点（即在编号为id的节点前面插入新节点），返回新插入节点的编号。
 * 2. int insertBack(Info info)，在链表末尾插入新节点，返回新节点的编号。
 * 3. void erase(int id)，删除编号为id的节点。
 * 4. void splice(int id, int fromId, int toId)，将 [fromId, toId) 这一段的节点插入至编号为id的节点处（即在编号为id的节点前面插入这一段）。
 * 5. void swap(int id1, int id2)，交换节点id1和id2在链表中位置。
 * 6. void reverse()，反转链表。
 *
 * 私有方法说明：
 * 1. int allocateId() 为新节点分配编号，返回申请到的编号。
 */

#include <bits/stdc++.h>

using i64 = long long;

class ArrayLinkedList {
public:
    static constexpr int NULLPTR = -1;
    struct Info {
        i64 v;

        Info() : v(0) {}
        Info(i64 v) : v(v) {}
    };
    struct Node {
        int prev, next;
        Info info;

        Node(): prev(NULLPTR), next(NULLPTR) {}
        Node(int prev, int next, Info info): prev(prev), next(next), info(info) {}
    };

    int sz = 0, head = 0, tail = 1;
    std::vector<Node> nodes;
    std::queue<int> spareIds;

    ArrayLinkedList() {
        nodes.push_back(Node(1, 1, Info()));
        nodes.push_back(Node(0, 0, Info()));
    }

    int insert(int id, Info &info) {
        int newId = allocateId();
        nodes[newId] = Node(nodes[id].prev, id, info);
        nodes[nodes[id].prev].next = newId;
        nodes[id].prev = newId;

        return newId;
    }

    int insertBack(Info info) { return insert(tail, info); }

    void erase(int id) {
        nodes[nodes[id].prev].next = nodes[id].next;
        nodes[nodes[id].next].prev = nodes[id].prev;

        spareIds.push(id);
        sz -= 1;
    }

    void splice(int id, int fromId, int toId) {
        int next;
        for (int cur = fromId; cur != toId; cur = next) {
            if (cur == id) { break; }
            next = nodes[cur].next;

            nodes[nodes[cur].prev].next = nodes[cur].next;
            nodes[nodes[cur].next].prev = nodes[cur].prev;
            nodes[cur].prev = nodes[id].prev;
            nodes[cur].next = id;
            nodes[nodes[id].prev].next = cur;
            nodes[id].prev = cur;
        }
    }

    void swap(int id1, int id2) {
        if (nodes[id2].next == id1) { std::swap(id1, id2); }
        int id2Next = nodes[id2].next;
        splice(id1, id2, id2Next);
        splice(id2Next, id1, nodes[id1].next);
    }

    void reverse() {
        if (sz == 0) { return; }

        int id = nodes[head].next, prev;
        for (int cur = nodes[tail].prev; cur != id; cur = prev) {
            prev = nodes[cur].prev;
            splice(id, cur, nodes[cur].next);
        }
    }

    int size() { return sz; }

private:
    int allocateId() {
        sz += 1;
        if (!spareIds.empty()) {
            int id = spareIds.front(); spareIds.pop();
            return id;
        }

        nodes.push_back(Node());
        return nodes.size() - 1;
    }
};
