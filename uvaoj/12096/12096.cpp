#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::stack<int> stk;
    std::map<std::set<int>, int> m;
    std::vector<std::set<int>> setCache;

    auto getSetId = [&](const std::set<int> &s) -> int {
        auto it = m.find(s);
        if (it == m.end()) {
            m[s] = setCache.size();
            setCache.push_back(s);
            return setCache.size() - 1;
        }

        return it->second;
    };

    auto push = [&]() {
        int id = getSetId(std::set<int>());
        stk.push(id);
    };

    auto dup = [&]() { stk.push(stk.top()); };

    auto setOps = [&](char mode) {
        int set1Id = stk.top(); stk.pop();
        int set2Id = stk.top(); stk.pop();

        std::set<int> set1 = setCache[set1Id], set2 = setCache[set2Id];
        std::set<int> nSet;
        if (mode == 'U') {
            std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(nSet, nSet.begin()));
        }
        else if (mode == 'I') {
            std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(nSet, nSet.begin()));
        }
        else if (mode == 'A') {
            set2.insert(set1Id);
            std::swap(nSet, set2);
        }

        int id = getSetId(nSet);
        stk.push(id);
    };

    std::string command;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command[0] == 'P') { push(); }
        else if (command[0] == 'D') { dup(); }
        else { setOps(command[0]); }

        std::cout << setCache[stk.top()].size() << '\n';
    }
    std::cout << "***" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
