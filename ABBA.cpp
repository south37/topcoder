#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

typedef unsigned long long unsigned int ulong;

class ABBA {
public:
    std::string canObtain(std::string initial, std::string target) {
        ulong i = changeToLong(initial);
        if (fromTarget(target, initial.length()) == i) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
    ulong fromTarget(const std::string& target, int len) {
        ulong r = changeToLong(target);
        int r_len = target.length();
        while (r_len > len) {
            if (canRemoveA(r)) {
                r = removeA(r);
            } else {
                r = removeB(r, r_len);
            }
            r_len -= 1;
        }
        return r;
    }
    bool canRemoveA(ulong n) {
        return (n & 0x01) == 0;
    }
    ulong removeA(ulong n) {
        return n >> 1;
    }
    ulong removeB(ulong n, int len) {
        return reverseWithLen((n >> 1), len - 1);
    }
    ulong changeToLong(const std::string& s) {
        ulong result = 0;
        auto end = s.end();
        for(auto it = s.begin(); it != end; ++it) {
            result <<= 1;
            if (*it == 'B') {  // If 'A', 0 is set
                result += 1;
            }
        }
        return result;
    }
    ulong reverseWithLen(ulong n, int len) {
        return reverse(n) >> (sizeof(long) * CHAR_BIT - len);
    }
    ulong reverse(ulong n) {
        ulong rv = 0;
        std::size_t b = sizeof(ulong) * CHAR_BIT;
        for (std::size_t i = 0; i < b; ++i, n >>= 1) {
            rv = (rv << 1) | (n & 0x01);
        }
        return rv;
    }
};

int main(int argc, char** argv) {
    ABBA a0;
    std::cout << "Possible is expected, and got " << a0.canObtain("B", "ABBA") << std::endl;
    ABBA a1;
    std::cout << "Impossible is expected, and got " << a1.canObtain("AB", "ABB") << std::endl;
    ABBA a2;
    std::cout << "Impossible is expected, and got " << a2.canObtain("BBAB", "ABABABABB") << std::endl;
    ABBA a3;
    std::cout << "Possible is expected, and got " << a3.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA") << std::endl;
    ABBA a4;
    std::cout << "Impossible is expected, and got " << a4.canObtain("A", "BB") << std::endl;
}
