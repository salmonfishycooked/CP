#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int round = 1, r, c, n;
    while (std::cin >> r >> c) {
        if (r == 0) { break; }

        std::vector tracker(r + 1, std::vector<std::pair<int, int>>(c + 1));
        std::vector table(r + 1, std::vector<std::pair<int, int>>(c + 1));
        for (int row = 1; row <= r; row++) {
            for (int col = 1; col <= c; col++) {
                tracker[row][col] = table[row][col] = {row, col};
            }
        }

        auto updTrack = [&](int x, int y) {
            auto [oriR, oriC] = table[x][y];
            if (oriR != 0) {
                tracker[oriR][oriC] = {x, y};
            }
        };

        auto eraseTrack = [&](int x, int y) {
            auto [oriR, oriC] = table[x][y];
            if (oriR != 0) {
                tracker[oriR][oriC] = {0, 0};
            }
        };

        auto exchange = [&]() {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::swap(table[x1][y1], table[x2][y2]);
            updTrack(x1, y1);
            updTrack(x2, y2);
        };

        auto insert = [&](char mode) {
            int k;
            std::cin >> k;
            std::vector<int> waitList(k);
            for (int i = 0; i < k; i++) {
                std::cin >> waitList[i];
            }
            std::sort(waitList.begin(), waitList.end());

            if (mode == 'R') {
                for (int i = 0; i < k; i++) {
                    int insertIdx = waitList[i] + i;
                    table.insert(table.begin() + insertIdx, std::vector<std::pair<int, int>>(table[1].size()));
                    for (int row = insertIdx + 1; row < table.size(); row++) {
                        for (int col = 1; col < table[1].size(); col++) {
                            updTrack(row, col);
                        }
                    }
                }
            } else {
                for (int i = 0; i < k; i++) {
                    int insertIdx = waitList[i] + i;
                    for (int row = 1; row < table.size(); row++) {
                        table[row].insert(table[row].begin() + insertIdx, {0, 0});
                    }

                    for (int row = 1; row < table.size(); row++) {
                        for (int col = insertIdx + 1; col < table[1].size(); col++) {
                            updTrack(row, col);
                        }
                    }
                }
            }
        };

        auto del = [&](char mode) {
            int k;
            std::cin >> k;
            std::vector<int> waitList(k);
            for (int i = 0; i < k; i++) {
                std::cin >> waitList[i];
            }
            std::sort(waitList.begin(), waitList.end());

            if (mode == 'R') {
                for (int i = 0; i < k; i++) {
                    int deleteIdx = waitList[i] - i;
                    for (int col = 1; col < table[1].size(); col++) { eraseTrack(deleteIdx, col); }
                    table.erase(table.begin() + deleteIdx, table.begin() + deleteIdx + 1);
                    for (int row = deleteIdx; row < table.size(); row++) {
                        for (int col = 1; col < table[1].size(); col++) {
                            updTrack(row, col);
                        }
                    }
                }
            } else {
                for (int i = 0; i < k; i++) {
                    int deleteIdx = waitList[i] - i;
                    for (int row = 1; row < table.size(); row++) {
                        eraseTrack(row, deleteIdx);
                        table[row].erase(table[row].begin() + deleteIdx, table[row].begin() + deleteIdx + 1);
                    }

                    for (int row = 1; row < table.size(); row++) {
                        for (int col = deleteIdx; col < table[1].size(); col++) {
                            updTrack(row, col);
                        }
                    }
                }
            }
        };

        std::cin >> n;
        std::string cmd;
        while (n--) {
            std::cin >> cmd;
            if (cmd[0] == 'E') { exchange(); }
            else if (cmd[0] == 'I') { insert(cmd[1]); }
            else { del(cmd[1]); }
        }

        if (round > 1) { std::cout << '\n'; }

        std::cout << "Spreadsheet #" << round << '\n';
        int q;
        std::cin >> q;
        while (q--) {
            int row, col;
            std::cin >> row >> col;
            auto [nRow, nCol] = tracker[row][col];
            if (nRow == 0) {
                std::cout << "Cell data in (" << row << ',' << col << ") GONE" << '\n';
                continue;
            }
            std::cout << "Cell data in (" << row << ',' << col << ") moved to (" << nRow << ',' << nCol << ")" << '\n';
        }
        round += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
