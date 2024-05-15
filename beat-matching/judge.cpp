/**
 * Judge used to judge test cases between your answer and standard answer
 */

#include <bits/stdc++.h>

using i64 = int64_t;

// TEST_TIME is the total time in this test, unit: seconds
constexpr int TEST_TIME = 5;

/**
 * judge is the main logic for judge.
 * following is a judge example.
 * @return true if it passed
 */
bool judge() {
    int cnt1, cnt2;
    std::set<int> s1, s2;

    freopen("ans.out", "r", stdin);
    std::cin >> cnt1;
    for (int i = 0, tmp; i < cnt1; i++) {
        std::cin >> tmp;
        s1.insert(tmp);
    }

    freopen("main.out", "r", stdin);
    std::cin >> cnt2;
    for (int i = 0, tmp; i < cnt2; i++) {
        std::cin >> tmp;
        s2.insert(tmp);
    }

    return s1 == s2;
}

int main() {
    std::time_t start = std::time(nullptr);
    while (true) {
        system("generator.exe");
        system("ans.exe");
        system("main.exe");
        if (!judge()) {
            std::cerr << "Judge has founded a difference!" << '\n';
            return 0;
        }

        std::time_t now = std::time(nullptr);
        if (now - start >= TEST_TIME) {
            break;
        }
    }

    std::cout << "\033[0;32mAll test cases passed! (total time used: " << TEST_TIME << "s)\033[0m"  << '\n';
    return 0;
}
