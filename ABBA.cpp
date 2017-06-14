#include <iostream>
#include <string>

class ABBA {
public:
    std::string canObtain(std::string initial, std::string target) {
        shrinkFromTarget(target, initial.length());
        if (target == initial) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
    void shrinkFromTarget(std::string& target, int len) {
        int r_len = target.length();
        while (r_len > len) {
            if (canRemoveA(target)) {
                removeA(target);
            } else {
                removeB(target);
            }
            r_len -= 1;
        }
    }
    bool canRemoveA(const std::string& s) {
        return *(--s.end()) == 'A';
    }
    void removeA(std::string& s) {
        s.erase(--s.end());
    }
    void removeB(std::string& s) {
        s.erase(--s.end());
        std::reverse(s.begin(), s.end());
    }
};

int main(int argc, char** argv) {
    ABBA a0;
    std::cout << "Possible is expected, and got " << a0.canObtain("B", "ABBA") << std::endl;
    // std::string s("ABBA");
    // std::cout << s << std::endl;
    // a0.shrinkFromTarget(s, 1);
    // std::cout << s << std::endl;
    ABBA a1;
    std::cout << "Impossible is expected, and got " << a1.canObtain("AB", "ABB") << std::endl;
    ABBA a2;
    std::cout << "Impossible is expected, and got " << a2.canObtain("BBAB", "ABABABABB") << std::endl;
    ABBA a3;
    std::cout << "Possible is expected, and got " << a3.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA") << std::endl;
    ABBA a4;
    std::cout << "Impossible is expected, and got " << a4.canObtain("A", "BB") << std::endl;
}
