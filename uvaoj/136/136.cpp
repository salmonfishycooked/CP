#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::vector<i64> factors = {2, 3, 5};
    std::priority_queue<i64, std::vector<i64>, std::greater<>> q;
    std::set<i64> s;
    q.push(1);
    for (int i = 1; i < 1500; i++) {
        i64 num = q.top(); q.pop();
        for (auto factor : factors) {
            i64 newNum = num * factor;
            if (!s.count(newNum)) {
                s.insert(newNum);
                q.push(num * factor);
            }
        }
    }

    std::cout << "The 1500'th ugly number is " << q.top() << '.' << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
