#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, p;
    i64 m;
    std::cin >> n >> m >> p;
    p -= 1;
    n += 1;

    std::vector<std::pair<i64, int>> x(n);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> x[i].first;
        x[i].second = i;
    }
    x[n - 1] = {0, n - 1};

    int giftIdx, startIdx;
    std::sort(x.begin(), x.end());
    std::vector<int> oriTo(n);
    for (int i = 0; i < n; i++) {
        oriTo[x[i].second] = i;
        if (x[i].second == p) {
            giftIdx = i;
        }
        if (x[i].second == n - 1) {
            startIdx = i;
        }
    }

    int cnt = 0, l = 0;
    bool included = false;
    std::vector<std::pair<int, int>> rec;
    for (int r = startIdx; r < n; r++) {
        i64 curM = m;
        if (l <= giftIdx && giftIdx <= r) {
            included = true;
            curM += 5;
            while (l - 1 >= 0 && (std::abs(x[l - 1].first) + std::abs(x[r].first)) * 2 <= curM) {
                l -= 1;
            }
        }

        while (l < startIdx && (std::abs(x[l].first) + std::abs(x[r].first)) * 2 > curM) {
            l += 1;
            if ((giftIdx < l || giftIdx > r) && included) {
                curM -= 5;
                included = false;
            }
        }

        if ((std::abs(x[l].first) + std::abs(x[r].first)) * 2 <= curM) {
            if (r - l > cnt) {
                cnt = r - l;
                rec.clear();
                rec.emplace_back(l, r);
            } else if (r - l == cnt && cnt != 0) {
                rec.emplace_back(l, r);
            }
        }
    }

    std::cout << cnt << '\n';
    if (cnt == 0) { return; }

    int i = 0, j = rec.size() - 1;
    for (int k = 0; k < n - 1; k++) {
        int curIdx = oriTo[k];
        if (curIdx < rec[i].first || curIdx > rec[j].second) { continue; }
        while (i < j && rec[i].second < curIdx) { i += 1; }
        while (i < j && rec[j].first > curIdx) { j -= 1; }
        if (i == j) { break; }
    }

    int leftBound = rec[i].first, rightBound = rec[i].second;
    if (giftIdx >= leftBound && giftIdx <= rightBound) {
        if (giftIdx >= startIdx) {
            for (int k = startIdx + 1; k <= rightBound; k++) {
                std::cout << x[k].second + 1 << ' ';
            }
            for (int k = startIdx - 1; k >= leftBound; k--) {
                std::cout << x[k].second + 1 << ' ';
            }
            return;
        }

        for (int k = startIdx - 1; k >= leftBound; k--) {
            std::cout << x[k].second + 1 << ' ';
        }
        for (int k = startIdx + 1; k <= rightBound; k++) {
            std::cout << x[k].second + 1 << ' ';
        }
        return;
    }
    for (int k = leftBound; k <= rightBound; k++) {
        if (k != startIdx) {
            std::cout << x[k].second + 1 << ' ';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
