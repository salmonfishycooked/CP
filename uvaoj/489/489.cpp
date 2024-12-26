#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int round;
    std::string ans, guess;
    std::vector<std::string> msgs = {"You win.", "You chickened out.", "You lose."};
    while ((std::cin >> round) && (round != -1)) {
        std::cin >> ans >> guess;

        int state = 1, kindCnt = 0;
        std::vector<int> cnt(26);
        for (auto ch : ans) {
            kindCnt += !cnt[ch - 'a'];
            cnt[ch - 'a'] += 1;
        }

        int myKindCnt = 0, wrongCnt = 0;
        std::vector<int> cnt2(26);
        for (auto ch : guess) {
            if (!cnt[ch - 'a'] || cnt[ch - 'a'] && cnt2[ch - 'a']) {
                wrongCnt += 1;
                if (wrongCnt == 7) {
                    state = 2;
                    break;
                }
                continue;
            }
            if (!cnt2[ch - 'a']) {
                cnt2[ch - 'a'] += 1;
                myKindCnt += 1;
                if (myKindCnt == kindCnt) {
                    state = 0;
                    break;
                }
            }
        }

        std::cout << "Round " << round << '\n';
        std::cout << msgs[state] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
