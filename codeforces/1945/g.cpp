#include <bits/stdc++.h>

using i64 = int64_t;

struct cmp {
    bool operator()(const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) {
        if (std::get<0>(a) == std::get<0>(b)) {
            return std::get<1>(a) > std::get<1>(b);
        }
        return std::get<0>(a) < std::get<0>(b);
    }
};

void solve() {
    int n, D;
    std::cin >> n >> D;

    std::queue<int> q1;
    std::vector<int> k(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i] >> s[i];
        q1.push(i);
    }

    std::vector<int> sufMaxPriority(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sufMaxPriority[i] = std::max(sufMaxPriority[i + 1], k[i]);
    }

    int timestamp = 0;
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, cmp> q2;
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> q3;
    for (int time = 1; time <= D; time++) {
        int id = q1.front();
        if (!q2.empty() && std::get<0>(q2.top()) > sufMaxPriority[n - q1.size()]) {
            id = std::get<2>(q2.top());
            q2.pop();
        } else {
            q1.pop();
            if (q1.empty()) {
                std::cout << time << '\n';
                return;
            }
        }

        int retTime = time + s[id];
        q3.emplace(retTime, s[id], id);
        while (!q3.empty() && std::get<0>(q3.top()) == time) {
            auto [x1, x2, outId] = q3.top();
            q2.emplace(k[outId], timestamp, outId);
            q3.pop();
            timestamp += 1;
        }
    }

    std::cout << -1 << '\n';
};

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
