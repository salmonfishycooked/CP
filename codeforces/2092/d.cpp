#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    std::vector<char> charSet = {'L', 'I', 'T'};
    std::unordered_map<int, int> typeMap = {{'I' + 'T', 0}, {'L' + 'T', 1}, {'L' + 'I', 2}};
    std::unordered_map<char, int> charMap = {{'L', 0}, {'I', 1}, {'T', 2}};
    std::unordered_map<int, char> neededMap = {{0, 'L'}, {1, 'I'}, {2, 'T'}};

    void solve() {
        int n;
        std::cin >> n;

        int m = 2 * n;

        std::list<char> s;
        std::vector<int> typeCnt(3);
        std::vector<std::pair<int, char>> charCnt(3);
        for (int i = 0; i < 3; i++) { charCnt[i] = {0, charSet[i]}; }
        for (int i = 0; i < n; i++) {
            char ch;
            std::cin >> ch;
            s.push_back(ch);
            charCnt[charMap[ch]].first += 1;
            if (s.size() >= 2 && *s.rbegin() != *(++s.rbegin())) {
                typeCnt[typeMap[*s.rbegin() + *(++s.rbegin())]] += 1;
            }
        }

        if (std::accumulate(typeCnt.begin(), typeCnt.end(), 0) == 0) {
            std::cout << -1 << '\n';
            return;
        }

        std::sort(charCnt.begin(), charCnt.end());

        std::vector<int> priorities = {charMap[charCnt[0].second]};
        for (int i = 0; i < 3; i++) {
            if (i != priorities[0] && i != charMap[charCnt[1].second]) {
                priorities.push_back(i);
                break;
            }
        }
        priorities.push_back(charMap[charCnt[1].second]);

        std::vector<int> ops;
        auto taiga = [&]() -> void {
            for (auto typeId : priorities) {
                if (typeCnt[typeId]) {
                    ops.push_back(typeId);
                    typeCnt[typeId] -= 1;
                    for (int i = 0; i < 3; i++) {
                        if (i == typeId) { continue; }
                        typeCnt[i] += 1;
                    }
                    for (int i = 0; i < 3; i++) {
                        if (charCnt[i].second == neededMap[typeId]) {
                            charCnt[i].first += 1;
                            break;
                        }
                    }
                    break;
                }
            }
        };

        auto doIt = [&](int typeId) -> void {
            auto prev = s.begin(), it = ++s.begin();
            for (int idx = 1; it != s.end(); ++it, ++idx) {
                if (*it != *prev && typeMap[*it + *prev] == typeId) {
                    s.insert(it, neededMap[typeId]);
                    std::cout << idx << '\n';
                    break;
                }
                prev = it;
            }
        };

        while (charCnt[0].first < charCnt[1].first && ops.size() <= m) { taiga(); }

        priorities = {charMap[charCnt[0].second], charMap[charCnt[1].second], charMap[charCnt[2].second]};
        while (charCnt[0].first < charCnt[2].first && ops.size() <= m) { taiga(); }

        priorities = {charMap[charCnt[1].second], charMap[charCnt[2].second], charMap[charCnt[0].second]};
        while (charCnt[1].first < charCnt[2].first && ops.size() <= m) { taiga(); }

        if (ops.size() <= m) {
            std::cout << ops.size() << '\n';
            for (auto op : ops) { doIt(op); }
            return;
        }
        std::cout << -1 << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
