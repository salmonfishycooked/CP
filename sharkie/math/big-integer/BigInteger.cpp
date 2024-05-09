/**
 * 高精度整数 - BigInteger
 *
 * 目前只支持非负数的运算
 */

#include <bits/stdc++.h>

using i64 = int64_t;

class BigInteger {
public:
    static constexpr int BASE = 10;

    std::vector<int> s;

    BigInteger(i64 num = 0) {
        *this = num;
    }

    BigInteger &operator=(i64 num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);

        return *this;
    }

    BigInteger &operator=(const std::string &str) {
        s.clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            s.push_back(str[i] - '0');
        }

        return *this;
    }

    BigInteger operator+(const BigInteger &b) {
        BigInteger ret;
        ret.s.clear();

        for (int i = 0, exp = 0; ; i++) {
            if (exp == 0 && i >= s.size() && i >= b.s.size()) { break; }

            int x = exp;
            if (i < s.size()) {
                x += s[i];
            }
            if (i < b.s.size()) {
                x += b.s[i];
            }
            exp = x / BASE;
            ret.s.push_back(x % BASE);
        }

        return ret;
    }

    BigInteger operator+=(const BigInteger &b) {
        *this = *this + b;

        return *this;
    }

    BigInteger operator*(const BigInteger &b) {
        BigInteger ret = 0;
        for (int i = 0; i < b.s.size(); i++) {
            BigInteger cur;
            cur.s.clear();
            for (int j = 0; j < i; j++) {
                cur.s.push_back(0);
            }

            int op = b.s[i], exp = 0;
            for (int digit : s) {
                int x = exp + digit * op;
                cur.s.push_back(x % BASE);
                exp = x / BASE;
            }
            while (exp) {
                cur.s.push_back(exp % BASE);
                exp = exp / BASE;
            }

            ret += cur;
        }

        return ret;
    }

    BigInteger &operator*=(const BigInteger &b) {
        *this = *this * b;

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const BigInteger &x) {
        for (int i = x.s.size() - 1; i >= 0; i--) {
            out << x.s[i];
        }

        return out;
    }

    friend std::istream &operator>>(std::istream &in, BigInteger &x) {
        std::string str;
        in >> str;
        x = str;

        return in;
    }
};
