#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::map<char, int> m = {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
    std::vector<int> cnt(4);
    for (auto ch : s) {
        cnt[m[ch]] += 1;
    }

    int cmdCnt = 0;
    std::vector<int> remain(4);
    std::vector<int> cmd(4);
    for (int i = 0; i < 4; i += 2) {
        int minP = std::min(cnt[i], cnt[i + 1]);
        int maxP = std::max(cnt[i], cnt[i + 1]);
        if ((maxP - minP) % 2 != 0) {
            std::cout << "NO" << '\n';
            return;
        }

        cmd[i] = (maxP - minP) / 2;
        cmdCnt += cmd[i];
        remain[i] = minP, remain[i + 1] = minP;
        if (cnt[i] < cnt[i + 1]) {
            std::swap(cmd[i], cmd[i + 1]);
        }
    }

    if (cmdCnt == 0) {
        for (int i = 0; i < 4; i += 2) {
            if (remain[i] != 0) {
                cmdCnt = 2;
                cmd[i] += 1, cmd[i + 1] += 1;
                break;
            }
        }
    }

    if (cmdCnt == 0 || n - cmdCnt == 0) {
        std::cout << "NO" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cmd[m[s[i]]] > 0) {
            std::cout << 'R';
            cmd[m[s[i]]] -= 1;
            continue;
        }
        std::cout << 'H';
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
