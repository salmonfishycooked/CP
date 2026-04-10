#include <bits/stdc++.h>

using i64 = long long;

const double INF = 1e16;

struct Line {
public:
    i64 x, y, len;

    Line(i64 x, i64 y, i64 len) : x(x), y(y), len(len) {}

    bool operator<(const Line &l) {
        if (y != l.y) { return y > l.y; }
        if (x != l.x) { return x < l.x; }
        return len > l.len;
    }
};

class Solution {
public:
    void solve() {
        i64 n, X, Y;
        std::cin >> n >> X >> Y;

        std::vector<Line> lines;
        lines.reserve(n);
        for (i64 i = 0, x, y, l; i < n; ++i) {
            std::cin >> x >> y >> l;
            lines.push_back({x, y, l});
        }

        std::sort(lines.begin(), lines.end());

        i64 ans = 0;
        std::set<std::pair<double, double>> slops;
        slops.insert({INF, INF});
        slops.insert({-INF, -INF});
        for (const auto &line : lines) {
            const i64 x = line.x, y = line.y, len = line.len;
            const double k1 = 1.0 * (X - x) / (Y - y);
            const double k2 = 1.0 * (X - x - len) / (Y - y);
            ans += process(slops, k2, k1);
        }

        std::cout << ans << '\n';
    }

    bool process(std::set<std::pair<double, double>> &slops, double kl, double kr) {
        auto it = std::prev(slops.upper_bound({kl, INF}));
        if (it->first <= kl && kr <= it->second) { return false; }

        it = slops.lower_bound({kl, -INF});
        auto prevIt = std::prev(it);
        double left = kl, right = kr;
        if (prevIt->second >= kl) {
            it = prevIt;
            left = prevIt->first;
        }

        while (it != slops.end() && it->first <= right) {
            right = std::max(right, it->second);
            it = slops.erase(it);
        }
        slops.insert({left, right});

        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}