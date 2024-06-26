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

    std::ifstream ansFile("ans.out");
    ansFile >> cnt1;
    for (int i = 0, tmp; i < cnt1; i++) {
        ansFile >> tmp;
        s1.insert(tmp);
    }

    std::ifstream mainFile("main.out");
    mainFile >> cnt2;
    for (int i = 0, tmp; i < cnt2; i++) {
        mainFile >> tmp;
        s2.insert(tmp);
    }

    return s1 == s2;
}

/**
 * compile used to compile source codes
 * @return true if success
 */
bool compile() {
    std::cout << "compiling source code..." << '\n';
    if (system("g++ -o main.exe main.cpp")) {
        std::cerr << "main.cpp complied error!" << '\n';
        return false;
    }
    if (system("g++ -o ans.exe ans.cpp")) {
        std::cerr << "ans.cpp complied error!" << '\n';
        return false;
    }
    if (system("g++ -o generator.exe generator.cpp")) {
        std::cerr << "generator.cpp complied error!" << '\n';
        return false;
    }
    std::cout << "\033[0;32mcomplied ok!\033[0m" << '\n';

    return true;
}

int main() {
    bool compiledOK = compile();
    if (!compiledOK) {
        return 1;
    }

    int taskId = 1;
    std::time_t start = std::time(nullptr);
    while (true) {
        std::cout << "TASK #" << taskId << ": ";
        system("generator.exe");
        system("ans.exe");
        system("main.exe");
        if (!judge()) {
            std::cout << "\033[31;4mWRONG ANSWER\033[0m" << '\n';
            return 0;
        }
        std::cout << "\033[0;32mPASSED\033[0m" << '\n';

        std::time_t now = std::time(nullptr);
        if (now - start >= TEST_TIME) {
            break;
        }

        taskId += 1;
    }

    std::cout << "\033[0;32mAll " << taskId << " test cases passed! (total time used: " << TEST_TIME << "s)\033[0m"  << '\n';
    return 0;
}
