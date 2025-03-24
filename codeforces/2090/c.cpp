#include <bits/stdc++.h>

using i64 = long long;

struct cmp {
    bool operator() (const std::tuple<int, int, int, int, int> &p1, const std::tuple<int, int, int, int, int> &p2) const {
        auto [x1, y1, z1, oriX1, oriY1] = p1;
        auto [x2, y2, z2, oriX2, oriY2] = p2;
        if (x1 + y1 == x2 + y2) {
            if (oriX1 == oriX2) { return oriY1 > oriY2; }
            return oriX1 > oriX2;
        }
        return x1 + y1 > x2 + y2;
    }
};

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::queue<std::pair<int, int>> unUsed;
        for (int round = 0; unUsed.size() < n; round++) {
            for (int x = 1, y = round * 3 + 1; y >= 1; x += 3, y -= 3) {
                unUsed.emplace(x, y);
            }
        }

        std::priority_queue<std::tuple<int, int, int, int, int>, std::vector<std::tuple<int, int, int, int, int>>, cmp> used;
        for (int i = 0, num; i < n; i++) {
            std::cin >> num;
            if (num == 0) {
                auto [x, y] = unUsed.front(); unUsed.pop();
                std::cout << x << ' ' << y << '\n';
                used.emplace(x, y + 1, 3, x, y + 1);
                continue;
            }

            int flag = 1;
            auto [x1, y1] = unUsed.front();
            if (!used.empty()) {
                auto [x2, y2, cnt, oriX2, oriY2] = used.top();
                if (x2 + y2 < x1 + y1 || (x1 + y1 == x2 + y2 && oriX2 < x1) || (x1 + y1 == x2 + y2 && oriX2 == x1 && oriY2 < y1)) {
                    flag = 0;
                }
            }

            if (flag) {
                auto [x, y] = unUsed.front(); unUsed.pop();
                std::cout << x << ' ' << y << '\n';
                used.emplace(x, y + 1, 3, x, y + 1);
            } else {
                auto [x, y, cnt, oriX, oriY] = used.top(); used.pop();
                int sitX = x, sitY = y;
                if (cnt == 3) { x += 1; y -= 1; oriX += 1; oriY -= 1; }
                if (cnt == 2) { x += 1; y += 2; oriY += 1;}
                if (cnt == 1) { sitX -= 1; sitY -= 1; }
                cnt -= 1;
                if (cnt >= 1) { used.emplace(x, y, cnt, oriX, oriY); }
                std::cout << sitX << ' ' << sitY << '\n';
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
