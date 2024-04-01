#include <bits/stdc++.h>

void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    x--;

    int r;
    char c;
    std::queue<int> q;
    q.push(x);
    while (m--) {
        std::cin >> r >> c;
        int sz = (int) q.size();
        std::set<int> exist;
        while (sz--) {
            int id = q.front(); q.pop();
            if (c != '0' && exist.find((id - r + n) % n) == exist.end()) {
                q.push((id - r + n) % n);
                exist.insert((id - r + n) % n);
            }
            if (c != '1' && exist.find((id + r) % n) == exist.end()) {
                q.push((id + r) % n);
                exist.insert((id + r) % n);
            }
        }
    }

    std::vector<int> ans(q.size());
    for (int & an : ans) {
        an = q.front();
        q.pop();
    }

    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (auto id : ans) {
        std::cout << id + 1 << ' ';
    }
    std::cout << '\n';
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
