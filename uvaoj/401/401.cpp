#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::unordered_map<int, int> m = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'},
    {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'},
{'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
{'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'}, {'8', '8'}};

    std::string str;
    while (std::cin >> str) {
        int n = str.length(), pali = 1, mirror = 1;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (str[i] != str[j]) { pali = 0; }
            if (m.find(str[i]) == m.end() || m[str[i]] != str[j]) { mirror = 0; }
        }

        std::cout << str;
        if (pali && mirror) {
            std::cout << " -- is a mirrored palindrome.";
        } else if (pali) {
            std::cout << " -- is a regular palindrome.";
        } else if (mirror) {
            std::cout << " -- is a mirrored string.";
        } else {
            std::cout << " -- is not a palindrome.";
        }
        std::cout << "\n\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
