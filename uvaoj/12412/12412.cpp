#include <bits/stdc++.h>

using i64 = long long;

constexpr double EPS = 1e-5;

class SPMS {
private:
    struct Student {
        std::string sid, cid, name;
        int s1, s2, s3, s4;
    };

    std::vector<Student> records;

    void drawMain() {
        std::cout << "Welcome to Student Performance Management System (SPMS)." << '\n';
        std::cout << '\n';
        std::cout << "1 - Add" << '\n';
        std::cout << "2 - Remove" << '\n';
        std::cout << "3 - Query" << '\n';
        std::cout << "4 - Show ranking" << '\n';
        std::cout << "5 - Show Statistics" << '\n';
        std::cout << "0 - Exit" << '\n';
        std::cout << '\n';
    }

    void drawAdd() {
        while (1) {
            std::cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << '\n';
            Student stu;
            std::cin >> stu.sid;
            if (stu.sid == "0") { break; }
            std::cin >> stu.cid >> stu.name >> stu.s1 >> stu.s2 >> stu.s3 >> stu.s4;

            if (isDuplicated(stu.sid)) {
                std::cout << "Duplicated SID." << '\n';
                continue;
            }

            insert(stu);
        }
    }

    void drawRemove() {
        while (1) {
            std::cout << "Please enter SID or name. Enter 0 to finish." << '\n';

            std::string str;
            std::cin >> str;
            if (str == "0") { break; }

            int deletedCnt = 0;
            deletedCnt += deleteBySid(str);
            if (deletedCnt == 0) { deletedCnt += deletedByName(str); }

            std::cout << deletedCnt << " student(s) removed." << '\n';
        }
    }

    void drawQuery() {
        while (1) {
            std::cout << "Please enter SID or name. Enter 0 to finish." << '\n';

            std::string str;
            std::cin >> str;
            if (str == "0") { break; }

            std::vector<Student> students;
            students = queryBySid(str);
            if (students.empty()) { students = queryByName(str); }

            for (auto &stu : students) {
                int totalScore = stu.s1 + stu.s2 + stu.s3 + stu.s4;
                double averageScore = totalScore / 4.0;
                std::cout << getRank(totalScore) << ' ';
                std::cout << stu.sid << ' ' << stu.cid << ' ' << stu.name << ' '
                << stu.s1 << ' ' << stu.s2 << ' ' << stu.s3 << ' ' << stu.s4 << ' '
                << totalScore << ' ' << std::fixed << std::setprecision(2) << (averageScore + EPS) << '\n';
            }
        }
    }

    void drawRanklist() {
        std::cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << '\n';
    }

    void drawStat() {
        std::cout << "Please enter class ID, 0 for the whole statistics." << '\n';

        std::string str;
        std::cin >> str;

        if (str == "0") { printStat(records); }
        else {
            std::vector<Student> students = queryByCid(str);
            printStat(students);
        }
    }

    int getRank(int totalScore) {
        int rank = 1;
        for (auto &stu : records) {
            int stuScore = stu.s1 + stu.s2 + stu.s3 + stu.s4;
            rank += totalScore < stuScore;
        }

        return rank;
    }

    bool isDuplicated(const std::string &sid) {
        for (auto &stu : records) {
            if (stu.sid == sid) { return true; }
        }

        return false;
    }

    void insert(const Student &student) {
        records.push_back(student);
    }

    int deleteBySid(const std::string &sid) {
        for (auto it = records.begin(); it != records.end(); it++) {
            if (it->sid == sid) {
                records.erase(it);
                return 1;
            }
        }

        return 0;
    }

    int deletedByName(const std::string &name) {
        int cnt = 0;
        for (int i = records.size() - 1; i >= 0; i--) {
            if (records[i].name == name) {
                cnt += 1;
                records.erase(records.begin() + i);
            }
        }

        return cnt;
    }

    std::vector<Student> queryBySid(const std::string &sid) {
        std::vector<Student> students;
        for (auto &stu : records) {
            if (stu.sid == sid) {
                students.push_back(stu);
                break;
            }
        }

        return students;
    }

    std::vector<Student> queryByName(const std::string &name) {
        std::vector<Student> students;
        for (auto &stu : records) {
            if (stu.name == name) {
                students.push_back(stu);
            }
        }

        return students;
    }

    std::vector<Student> queryByCid(const std::string &cid) {
        std::vector<Student> students;
        for (auto &stu : records) {
            if (stu.cid == cid) {
                students.push_back(stu);
            }
        }

        return students;
    }

    void printStat(const std::vector<Student> &students) {
        int chinesePassed = 0, mathPassed = 0, englishPassed = 0, programmingPassed = 0;
        int passedAll = 0, passedThree = 0, passedTwo = 0, passedOne = 0, failedAll = 0;
        i64 chineseSum = 0, mathSum = 0, englishSum = 0, programmingSum = 0;
        double chineseAvg, mathAvg, englishAvg, programmingAvg;

        for (auto &stu : students) {
            chineseSum += stu.s1;
            mathSum += stu.s2;
            englishSum += stu.s3;
            programmingSum += stu.s4;

            chinesePassed += stu.s1 >= 60;
            mathPassed += stu.s2 >= 60;
            englishPassed += stu.s3 >= 60;
            programmingPassed += stu.s4 >= 60;

            int passed = 0;
            passed += stu.s1 >= 60;
            passed += stu.s2 >= 60;
            passed += stu.s3 >= 60;
            passed += stu.s4 >= 60;
            switch (passed) {
                case 4: passedAll += 1;
                case 3: passedThree += 1;
                case 2: passedTwo += 1;
                case 1: passedOne += 1; break;
                default: failedAll += 1;
            }
        }

        chineseAvg = (double) chineseSum / students.size() + EPS;
        mathAvg = (double) mathSum / students.size() + EPS;
        englishAvg = (double) englishSum / students.size() + EPS;
        programmingAvg = (double) programmingSum / students.size() + EPS;

        std::cout << "Chinese" << '\n';
        std::cout << "Average Score: " << std::fixed << std::setprecision(2) << chineseAvg << '\n';
        std::cout << "Number of passed students: " << chinesePassed << '\n';
        std::cout << "Number of failed students: " << (students.size() - chinesePassed) << '\n';
        std::cout << '\n';

        std::cout << "Mathematics" << '\n';
        std::cout << "Average Score: " << std::fixed << std::setprecision(2) << mathAvg << '\n';
        std::cout << "Number of passed students: " << mathPassed << '\n';
        std::cout << "Number of failed students: " << (students.size() - mathPassed) << '\n';
        std::cout << '\n';

        std::cout << "English" << '\n';
        std::cout << "Average Score: " << std::fixed << std::setprecision(2) << englishAvg << '\n';
        std::cout << "Number of passed students: " << englishPassed << '\n';
        std::cout << "Number of failed students: " << (students.size() - englishPassed) << '\n';
        std::cout << '\n';

        std::cout << "Programming" << '\n';
        std::cout << "Average Score: " << std::fixed << std::setprecision(2) << programmingAvg << '\n';
        std::cout << "Number of passed students: " << programmingPassed << '\n';
        std::cout << "Number of failed students: " << (students.size() - programmingPassed) << '\n';
        std::cout << '\n';

        std::cout << "Overall:" << '\n';
        std::cout << "Number of students who passed all subjects: " << passedAll << '\n';
        std::cout << "Number of students who passed 3 or more subjects: " << passedThree << '\n';
        std::cout << "Number of students who passed 2 or more subjects: " << passedTwo << '\n';
        std::cout << "Number of students who passed 1 or more subjects: " << passedOne << '\n';
        std::cout << "Number of students who failed all subjects: " << failedAll << '\n';
        std::cout << '\n';
    }

public:
    explicit SPMS() = default;

    void run() {
        int cmd;
        while (1) {
            drawMain();
            std::cin >> cmd;
            if (cmd == 0) { break; }

            switch (cmd) {
                case 1: drawAdd(); break;
                case 2: drawRemove(); break;
                case 3: drawQuery(); break;
                case 4: drawRanklist(); break;
                case 5: drawStat(); break;
            }
        }
    }
};

void solve() {
    SPMS spms;
    spms.run();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
