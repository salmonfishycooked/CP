/**
 * 优先队列 (Priority Queue)
 * 支持按编号插入，按编号删除，按编号修改。
 *
 * 方法说明：
 * 1. void push(int id, const T &v)，将编号为 id，值为 v 的节点入堆。
 * 2. void pop()，弹出堆顶。
 * 3. void popById(int id)，弹出编号为 id 的节点。
 * 4. std::pair<T, int> top()，取得堆顶元素，pair 的第一个元素为值，第二个元素为其编号，即 id。
 * 5. std::pair<T, int> getById(int id)，返回编号为 id 的节点情况。
 * 6. void modify(int id, const T &v)，修改编号为 id 的节点的值。
 *
 * 特别说明：
 * 模板 Compare = std::less<> 是大顶堆，Compare = std::greater<> 是小顶堆
 */

#include <bits/stdc++.h>

template <typename T, typename Compare = std::less<>>
class PriorityQueue {
public:
    std::vector<std::pair<T, int>> ele;
    std::vector<int> trace;

    explicit PriorityQueue() = default;

    void push(int id, const T &v) {
        expandTrace(id);

        if (trace[id] != -1) {
            modify(id, v);
            return;
        }

        trace[id] = ele.size();
        ele.emplace_back(v, id);
        up(ele.size() - 1);
    }

    void pop() {
        assert(!ele.empty());

        trace[ele[ele.size() - 1].second] = 0;
        trace[ele[0].second] = -1;
        std::swap(ele[0], ele[ele.size() - 1]);
        ele.pop_back();
        adjust(0);
    }

    void popById(int id) {
        assert(id < trace.size() && trace[id] != -1);

        int heapId = trace[id];
        trace[ele[ele.size() - 1].second] = trace[id];
        trace[id] = -1;
        std::swap(ele[heapId], ele[ele.size() - 1]);
        ele.pop_back();
        adjust(heapId);
    }

    std::pair<T, int> getById(int id) {
        assert(id < trace.size() && trace[id] != -1);

        return ele[trace[id]];
    }

    std::pair<T, int> top() {
        assert(!ele.empty());

        return ele[0];
    }

    void modify(int id, const T &v) {
        int heapId = trace[id];
        ele[heapId].first = v;
        adjust(heapId);
    }

    int size() {
        return ele.size();
    }

    bool empty() {
        return ele.empty();
    }

private:
    void up(int heapId) {
        int cur = heapId;
        while (cur > 0) {
            int fa = (cur - 1) >> 1;
            if (!Compare()(ele[fa], ele[cur])) { break; }

            int faId = ele[fa].second, curId = ele[cur].second;
            trace[faId] = cur, trace[curId] = fa;

            std::swap(ele[fa], ele[cur]);
            cur = fa;
        }
    }

    void down(int heapId) {
        int cur = heapId;
        while (cur * 2 + 1 < ele.size()) {
            int candidate = cur * 2 + 1, rChild = cur * 2 + 2;
            if (rChild < ele.size() && !Compare()(ele[rChild], ele[candidate])) {
                candidate = rChild;
            }

            if (!Compare()(ele[cur], ele[candidate])) { break; }

            int curId = ele[cur].second, candidateId = ele[candidate].second;
            trace[curId] = candidate, trace[candidateId] = cur;

            std::swap(ele[cur], ele[candidate]);
            cur = candidate;
        }
    }

    void adjust(int heapId) {
        up(heapId);
        down(heapId);
    }

    void expandTrace(int maxId) {
        if (maxId >= trace.size()) {
            trace.resize(maxId + 1, -1);
        }
    }
};