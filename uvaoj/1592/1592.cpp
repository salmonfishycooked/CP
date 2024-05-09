#include <bits/stdc++.h>

using i64 = int64_t;

void solve(int n, int m) {
    std::cin.get();
    std::vector data(n, std::vector<std::string>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::string str;
            char ch;
            do {
                std::cin.get(ch);
                if (ch != ',' && ch != '\n') {
                    str.push_back(ch);
                }
            } while (ch != ',' && ch != '\n');
            data[i][j] = str;
        }
    }


    for (int col1 = 0; col1 < m; col1++) {
        for (int col2 = col1 + 1; col2 < m; col2++) {
            std::map<std::pair<std::string, std::string>, int> st;
            for (int i = 0; i < n; i++) {
                auto it = st.find({data[i][col1], data[i][col2]});
                if (it != st.end()) {
                    std::cout << "NO" << '\n';
                    std::cout << it->second + 1 << ' ' << i + 1 << '\n';
                    std::cout << col1 + 1 << ' ' << col2 + 1 << '\n';
                    return;
                }
                st[{data[i][col1], data[i][col2]}] = i;
            }
        }
    }

    std::cout << "YES" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m) {
        solve(n, m);
    }

    return 0;
}
