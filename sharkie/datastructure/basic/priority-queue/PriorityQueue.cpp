/**
 * 优先队列 (Priority Queue)
 * 支持按编号插入，按编号删除，按编号修改。
 *
 * 方法说明：
 * 1. int push(const T &v)，新增一个值为 v 的节点入堆，返回该新增节点的编号。
 * 2. T top()，返回栈顶节点所存储的数据。
 * 3. T get(const int id)，返回编号为 id 的节点所存储的数据。
 * 4. void modify(const int id, const T &data)，修改编号为 id 的节点的数据为 data。
 * 5. int pop()，弹出堆顶的节点，并返回它的编号。
 * 6. void popById(const int id)，弹出编号为 id 的节点。
 * 7. bool empty()，检查堆是否为空。
 *
 * 特别说明：
 * 模板 T 是数据类型，Compare 是重载了 bool operator()(const T &t1, const T &t2) 的类。
 * （示例：Compare = std::less<> 是大顶堆，Compare = std::greater<> 是小顶堆）
 */

#include <bits/stdc++.h>

template <typename T, typename Compare = std::less<>>
class PriorityQueue {
public:
    explicit PriorityQueue(Compare compare = Compare()) : ele(std::vector<Elem>(0)), trace(std::vector<int>(0)),
    compare(compare), nextId(0), avai(std::vector<int>(0)) {}

    int push(const T &data) {
        const int id = newId();
        expandTraceIfNeeded(id);

        ele.push_back({data, id});
        trace[id] = ele.size() - 1;
        adjust(ele.size() - 1);

        return id;
    }

    T top() {
        assert(!ele.empty());

        return ele[0].data;
    }

    T get(const int id) {
        assert(trace.size() > id && trace[id] != -1);

        const int heapId = trace[id];
        return ele[heapId].data;
    }

    void modify(const int id, const T &data) {
        assert(trace.size() > id && trace[id] != -1);

        const int heapId = trace[id];
        ele[heapId].data = data;
        adjust(heapId);
    }

    int pop() {
        assert(!ele.empty());

        const int id = ele[0].id;
        ele[0] = ele[ele.size() - 1];
        trace[id] = -1;
        ele.pop_back();
        if (!ele.empty()) {
            trace[ele[0].id] = 0;
            adjust(0);
        }

        avai.push_back(id);

        return id;
    }

    void popById(const int id) {
        assert(trace.size() > id && trace[id] != -1);

        const int heapId = trace[id];
        ele[heapId] = ele[ele.size() - 1];
        trace[id] = -1;
        ele.pop_back();
        if (ele.size() != heapId) {
            trace[ele[heapId].id] = heapId;
            adjust(heapId);
        }

        avai.push_back(id);
    }

    bool empty() {
        return ele.empty();
    }

private:
    struct Elem {
        T data;
        int id;
    };

    std::vector<Elem> ele;
    std::vector<int> trace;

    Compare compare;

    int nextId;
    std::vector<int> avai;

    void adjust(const int heapId) {
        down(heapId);
        up(heapId);
    }

    void down(int heapId) {
        const int n = static_cast<int>(ele.size());
        while (true) {
            const int child1 = heapId * 2 + 1, child2 = child1 + 1;
            if (child1 >= n) {
                break;
            }

            int betterChild = child1;
            if (child2 < n && compare(ele[child1].data, ele[child2].data)) {
                betterChild = child2;
            }

            if (!compare(ele[heapId].data, ele[betterChild].data)) {
                break;
            }

            trace[ele[heapId].id] = betterChild;
            trace[ele[betterChild].id] = heapId;
            std::swap(ele[betterChild], ele[heapId]);
            heapId = betterChild;
        }
    }

    void up(int heapId) {
        while (heapId) {
            const int fa = (heapId - 1) / 2;
            if (!compare(ele[fa].data, ele[heapId].data)) {
                break;
            }

            trace[ele[heapId].id] = fa;
            trace[ele[fa].id] = heapId;
            std::swap(ele[fa], ele[heapId]);
            heapId = fa;
        }
    }

    int newId() {
        if (!avai.empty()) {
            const int id = avai.back();
            avai.pop_back();
            return id;
        }

        const int id = nextId++;
        return id;
    }

    void expandTraceIfNeeded(const int id) {
        if (trace.size() <= id) {
            trace.resize(id + 1, -1);
        }
    }
};
