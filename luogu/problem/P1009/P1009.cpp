#include <bits/stdc++.h>

using i64 = int64_t;

class BigInteger {
public:
    static constexpr int BASE = 100000000;
    static constexpr int IO_WIDTH = 8;

    char sign;
    constexpr static int SIGN_POSITIVE = 1;
    constexpr static int SIGN_NEGATIVE = -1;

    std::vector<int> s;

    BigInteger(i64 num = 0) {
        sign = SIGN_POSITIVE;
        *this = num;
    }

    BigInteger &operator=(i64 num) {
        sign = SIGN_POSITIVE;
        if (num < 0) {
            sign = SIGN_NEGATIVE;
            num = -num;
        }

        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);

        return *this;
    }

    BigInteger &operator=(const std::string &str) {
        if (str.empty()) {
            return *this;
        }

        int startIdx = 0;
        if (str[0] == '-') {
            sign = SIGN_NEGATIVE;
            startIdx = 1;
        }

        s.clear();
        for (int i = str.size() - 1; i >= startIdx; ) {
            int j = i - IO_WIDTH + 1;
            if (j >= startIdx) {
                s.push_back(std::atoi(str.substr(j, IO_WIDTH).c_str()));
                i -= IO_WIDTH;
                continue;
            }
            s.push_back(std::atoi(str.substr(startIdx, i - startIdx + 1).c_str()));
            break;
        }

        return *this;
    }

    BigInteger operator+(const BigInteger &b) const {
        BigInteger ret;
        if (sign == SIGN_NEGATIVE && b.sign == SIGN_NEGATIVE || sign == SIGN_POSITIVE && b.sign == SIGN_POSITIVE) {
            ret = plusNoSign(*this, b);
            ret.sign = sign;
            return ret;
        }
        if (sign == SIGN_NEGATIVE && b.sign == SIGN_POSITIVE) {
            BigInteger tt = *this;
            tt.sign = SIGN_POSITIVE;
            return b - tt;
        }
        if (sign == SIGN_POSITIVE && b.sign == SIGN_NEGATIVE) {
            BigInteger tt = b;
            tt.sign = SIGN_POSITIVE;
            return *this - tt;
        }

        return ret;
    }

    BigInteger &operator+=(const BigInteger &b) {
        *this = *this + b;

        return *this;
    }

    BigInteger operator-(const BigInteger &b) const {
        BigInteger ret;
        if (sign == SIGN_POSITIVE && b.sign == SIGN_POSITIVE) {
            if (*this > b) {
                ret = subNoSign(*this, b);
                return ret;
            }
            ret = subNoSign(b, *this);
            ret.sign = SIGN_NEGATIVE;
            return ret;
        }
        if (sign == SIGN_NEGATIVE && b.sign == SIGN_NEGATIVE) {
            if (b < *this) {
                ret = subNoSign(b, *this);
                return ret;
            }
            ret = subNoSign(*this, b);
            ret.sign = SIGN_NEGATIVE;
            return ret;
        }
        if (sign == SIGN_POSITIVE && b.sign == SIGN_NEGATIVE) {
            ret = plusNoSign(*this, b);
            return ret;
        }
        if (sign == SIGN_NEGATIVE && b.sign == SIGN_POSITIVE) {
            ret = plusNoSign(*this, b);
            ret.sign = SIGN_NEGATIVE;
            return ret;
        }

        return ret;
    }

    BigInteger &operator-=(const BigInteger &b) {
        *this = *this - b;

        return *this;
    }

    BigInteger operator*(const BigInteger &b) const {
        BigInteger ret = mulNoSign(*this, b);
        if (sign == SIGN_POSITIVE && b.sign == SIGN_NEGATIVE || sign == SIGN_NEGATIVE && b.sign == SIGN_POSITIVE) {
            ret.sign = SIGN_NEGATIVE;
        }

        return ret;
    }

    BigInteger &operator*=(const BigInteger &b) {
        *this = *this * b;

        return *this;
    }

    BigInteger operator/(const BigInteger &b) const {
        assert(b != 0);

        BigInteger ret = divNoSign(*this, b);
        if (sign == SIGN_POSITIVE && b.sign == SIGN_NEGATIVE || sign == SIGN_NEGATIVE && b.sign == SIGN_POSITIVE) {
            ret.sign = SIGN_NEGATIVE;
        }

        return ret;
    }

    BigInteger &operator/=(const BigInteger &b) {
        *this = *this / b;

        return *this;
    }

    BigInteger remainder(const BigInteger &val) const {
        BigInteger t1 = *this / val;
        BigInteger t2 = t1 * val;
        BigInteger t3 = *this - t2;
        return t3;
    }

    BigInteger mod(const BigInteger &m) const {
        BigInteger result = this->remainder(m);

        return (result.sign >= 0 ? result : result + m);
    }

    bool operator==(const BigInteger &b) const {
        if (s.size() == 1 && s[0] == 0 && b.s.size() == 1 && b.s[0] == 0) {
            return true;
        }
        if (sign != b.sign || s.size() != b.s.size()) {
            return false;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != b.s[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator>(const BigInteger &b) const {
        if (s.size() == 1 && s[0] == 0 && b.s.size() == 1 && b.s[0] == 0) {
            return false;
        }

        if (sign < 0 && b.sign > 0) {
            return false;
        }
        if (sign > 0 && b.sign < 0) {
            return true;
        }
        if (sign > 0 && b.sign > 0) {
            if (s.size() != b.s.size()) {
                return s.size() > b.s.size();
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] != b.s[i]) {
                    return s[i] > b.s[i];
                }
            }
        }
        if (sign < 0 && b.sign < 0) {
            if (s.size() != b.s.size()) {
                return s.size() < b.s.size();
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] != b.s[i]) {
                    return s[i] < b.s[i];
                }
            }
        }

        return false;
    }

    bool operator>=(const BigInteger &b) const {
        return *this > b || *this == b;
    }

    bool operator<(const BigInteger &b) const {
        return !(*this >= b);
    }

    bool operator<=(const BigInteger &b) const {
        return !(*this > b);
    }

    bool operator!=(const BigInteger &b) const {
        return !(*this == b);
    }

    friend std::ostream &operator<<(std::ostream &out, const BigInteger &x) {
        if (x.s.size() == 1 && x.s[0] == 0) {
            out << 0;
            return out;
        }

        if (x.sign == -1) {
            std::cout << '-';
        }

        out << x.s[x.s.size() - 1];
        for (int i = x.s.size() - 2; i >= 0; i--) {
            out << std::setw(IO_WIDTH) << std::setfill('0') << x.s[i];
        }

        return out;
    }

    friend std::istream &operator>>(std::istream &in, BigInteger &x) {
        x.sign = SIGN_POSITIVE;
        std::string str;
        in >> str;
        x = str;

        return in;
    }
private:
    /**
     * plusNoSign calculates the a + b, where a >= 0, b >= 0 (means without sign).
     * without sign means this function will ignore their sign (a and b)
     */
    static BigInteger plusNoSign(const BigInteger &a, const BigInteger &b) {
        BigInteger ret;
        ret.s.clear();

        for (int i = 0, exp = 0; ; i++) {
            if (exp == 0 && i >= a.s.size() && i >= b.s.size()) { break; }

            int x = exp;
            if (i < a.s.size()) {
                x += a.s[i];
            }
            if (i < b.s.size()) {
                x += b.s[i];
            }
            exp = x / BASE;
            ret.s.push_back(x % BASE);
        }

        return ret;
    }

    /**
     * subNoSign calculates the a - b, where a >= 0, b >= 0 (means without sign).
     * without sign means this function will ignore their sign (a and b)
     * Note: a needs to be greater or equal to b!
     */
    static BigInteger subNoSign(const BigInteger &a, const BigInteger &b) {
        BigInteger ret = a;
        ret.sign = SIGN_POSITIVE;

        for (int i = 0, exp = 0; ; i++) {
            if (exp == 0 && i >= b.s.size()) { break; }

            i64 subNum = exp;
            exp = 0;
            if (i < b.s.size()) {
                subNum += b.s[i];
            }
            if (ret.s[i] < subNum) {
                exp = 1;
                ret.s[i] += BASE;
            }
            ret.s[i] -= subNum;
        }

        while (ret.s.size() > 1 && ret.s[ret.s.size() - 1] == 0) {
            ret.s.pop_back();
        }

        return ret;
    }

    /**
     * mulNoSign calculates the a * b, where a >= 0, b >= 0 (means without sign).
     * without sign means this function will ignore their sign (a and b)
     */
    static BigInteger mulNoSign(const BigInteger &a, const BigInteger &b) {
        if (a == 0 || b == 0) { return 0; }

        BigInteger ret = 0;
        for (int i = 0; i < b.s.size(); i++) {
            BigInteger cur;
            cur.s.clear();
            for (int j = 0; j < i; j++) {
                cur.s.push_back(0);
            }

            i64 op = b.s[i], exp = 0;
            for (i64 digit : a.s) {
                i64 x = exp + digit * op;
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

    /**
     * divNoSign calculates the a / b, where a >= 0, b >= 0 (means without sign).
     * without sign means this function will ignore their sign (a and b)
     */
    static BigInteger divNoSign(BigInteger a, BigInteger b) {
        a.sign = SIGN_POSITIVE, b.sign = SIGN_POSITIVE;
        BigInteger ret;
        ret.s.clear();

        BigInteger cur = 0;
        for (int i = a.s.size() - 1; i >= 0; i--, cur *= BASE) {
            cur += a.s[i];
            if (cur < b) { continue; }

            int l = 0, r = BASE;
            while (l + 1 != r) {
                int mid = (l + r) >> 1;
                if (b * mid <= cur) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cur -= b * l;
            ret.s.push_back(l);
        }

        if (ret.s.empty()) {
            ret.s.push_back(0);
        }

        std::reverse(ret.s.begin(), ret.s.end());

        return ret;
    }
};

void solve() {
    int n;
    std::cin >> n;

    BigInteger ret = 1, f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
        ret += f;
    }

    std::cout << ret << '\n';
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
