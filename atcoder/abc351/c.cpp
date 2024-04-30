#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N;
    std::cin >> N;

    std::stack<int> s;
    for (int i = 0, tmp; i < N; i++) {
        std::cin >> tmp;
        while (!s.empty() && s.top() == tmp) {
            tmp = s.top() + 1;
            s.pop();
        }
        s.push(tmp);
    }

    std::cout << s.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
