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
            if (cur == id) { break;}
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

void solve() {
    int round = 1, n, m;
    while (std::cin >> n && std::cin >> m) {
        ArrayLinkedList list;
        std::vector<int> toId(n + 1);
        for (int i = 1; i <= n; i++) { toId[i] = list.insertBack(ArrayLinkedList::Info(i)); }

        int op, X, Y, reversed = 0;
        while (m--) {
            std::cin >> op;
            if (op != 4) { std::cin >> X >> Y; }

            if (op == 1 && reversed == 0 || op == 2 && reversed == 1) { list.splice(toId[Y], toId[X], list.nodes[toId[X]].next); }
            else if (op == 1 && reversed == 1 || op == 2 && reversed == 0) { list.splice(list.nodes[toId[Y]].next, toId[X], list.nodes[toId[X]].next); }
            else if (op == 3) { list.swap(toId[X], toId[Y]); }
            else { reversed = !reversed; }
        }

        i64 sum = 0;
        for (int cur = list.head, i = 1; i <= n; i++) {
            cur = list.nodes[cur].next;
            if ((i % 2 && !(n % 2 == 0 && reversed)) || (i % 2 == 0 && n % 2 == 0 && reversed)) {
                sum += list.nodes[cur].info.v;
            }
        }

        std::cout << "Case " << round << ": " << sum << '\n';
        round += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
