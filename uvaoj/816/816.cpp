#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    struct BfsNode {
        int x, y;
        char dir;
        std::vector<std::pair<int, int>> records;
    };

    std::map<char, int> visMap{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    std::map<char, int> dxMap{{'N', -1}, {'E', 0}, {'S', 1}, {'W', 0}};
    std::map<char, int> dyMap{{'N', 0}, {'E', 1}, {'S', 0}, {'W', -1}};

    std::pair<int, int> start, end;
    char dir;
    std::vector<std::vector<std::vector<std::string>>> grid;

    void init() { grid.assign(10, std::vector(10, std::vector<std::string>())); }

    void handleInput() {
        std::cin >> start.first >> start.second;
        std::cin >> dir;
        std::cin >> end.first >> end.second;

        while (true) {
            int x, y;
            std::cin >> x;
            if (x == 0) { break; }
            std::cin >> y;

            while (true) {
                std::string str;
                std::cin >> str;
                if (str == "*") { break; }

                grid[x][y].push_back(str);
            }
        }
    }

    void printAns(const BfsNode &node) {
        int outputCnt = 0;
        std::cout << ' ' << ' ';
        for (int i = 0; i < node.records.size(); i++) {
            auto &[x, y] = node.records[i];
            std::cout << '(' << x << ',' << y << ')';
            outputCnt += 1;
            if (outputCnt < 10 && i < node.records.size() - 1) { std::cout << ' '; }
            if (outputCnt == 10 && i < node.records.size() - 1) {
                outputCnt = 0;
                std::cout << '\n' << ' ' << ' ';
            }
        }
        std::cout << '\n';
    }

    char convertDir(char dir, char op) {
        if (op == 'F') { return dir; }
        if (op == 'L') {
            switch (dir) {
                case 'N': return 'W';
                case 'E': return 'N';
                case 'S': return 'E';
                case 'W': return 'S';
            }
        }

        switch (dir) {
            case 'N': return 'E';
            case 'E': return 'S';
            case 'S': return 'W';
            case 'W': return 'N';
        }
    }

    void solve() {
        std::string name;
        while (std::cin >> name) {
            if (name == "END") { break; }
            std::cout << name << '\n';

            init();
            handleInput();

            bool found = false;
            std::vector vis(10, std::vector(10, std::vector<bool>(4)));
            std::queue<BfsNode> q;
            q.push({start.first, start.second, dir, {{start.first, start.second}}});
            while (!q.empty()) {
                std::queue<BfsNode> helper;
                while (!q.empty()) {
                    auto node = q.front(); q.pop();
                    int curX = node.x, curY = node.y, dx = dxMap[node.dir], dy = dyMap[node.dir];
                    for (curX += dx, curY += dy; curX >= 1 && curX <= 9 && curY >= 1 && curY <= 9; curX += dx, curY += dy) {
                        if (!grid[curX][curY].empty() ||
                            curX == start.first && curY == start.second ||
                            curX == end.first && curY == end.second) { break; }
                    }
                    if (curX < 1 || curX > 9 || curY < 1 || curY > 9 || vis[curX][curY][visMap[node.dir]]) { continue; }

                    vis[curX][curY][visMap[node.dir]] = true;
                    node.x = curX, node.y = curY;
                    node.records.emplace_back(curX, curY);
                    if (curX == end.first && curY == end.second) {
                        printAns(node);
                        found = true;
                        break;
                    }

                    for (auto &str : grid[curX][curY]) {
                        if (str[0] != node.dir) { continue; }
                        for (int i = 1; i < str.size(); i++) {
                            BfsNode newNode = node;
                            newNode.dir = convertDir(node.dir, str[i]);
                            helper.push(newNode);
                        }
                        break;
                    }
                }

                if (found) { break; }
                q = helper;
            }

            if (!found) { std::cout << "  No Solution Possible" << '\n'; }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
