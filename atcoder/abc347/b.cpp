#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;

    int n = (int) s.size();

    std::set<std::string> st;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            st.insert(s.substr(i, j - i + 1));
        }
    }

    std::cout << st.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
