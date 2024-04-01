#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans = 0;
    std::vector<std::string> strs = {"mapie", "map", "pie"};
    for (auto &str : strs) {
        int pos = 0;
        while ((pos = (int) s.find(str, pos)) != std::string::npos) {
            s[pos + str.size() / 2] = '.';
            ans += 1;
        }
    }

    std::cout << ans << '\n';
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
