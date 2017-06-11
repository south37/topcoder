#include <iostream>
#include <map>
#include <queue>
#include <cstring>

class ABC {
public:
    std::string createString(int N, int K) {
        std::memset(sx, 0, sizeof(sx));
        if (!match(0, 0, 0, 0, K, N)) {
            return "";
        }
        return sx;
    }
    bool match(int i, int a, int b, int k, int K, int N) {
        if (i == N) {
            if (k == K) {
                return true;
            } else {
                return false;
            }
        }

        sx[i] = 'A';
        if (match(i + 1, a + 1, b, k, K, N)) {
            return true;
        }
        sx[i] = 'B';
        if (match(i + 1, a, b + 1, k + a, K, N)) {
            return true;
        }
        sx[i] = 'C';
        if (match(i + 1, a, b, k + a + b, K, N)) {
            return true;
        }
        return false;
    }
    char sx[35];
};

int main(int argc, char** argv) {
    ABC a0;
    // std::cout << "Input is (3, 3), expected is \"ABC\" and got \"" << a0.createString(3, 3) << "\"" << std::endl;
    std::cout << "Input is (3, 3), expected is \"ABC\" and got \"" << a0.createString(3, 3) << "\"" << std::endl;

    ABC a1;
    std::cout << "Input is (3, 0), expected is \"CBA\" and got \"" << a1.createString(3, 0) << "\"" << std::endl;

    ABC a2;
    std::cout << "Input is (5, 10), expected is \"\" and got \"" << a2.createString(5, 10) << "\"" << std::endl;

    ABC a3;
    std::cout << "Input is (15, 36), expected is \"CABBACCBAABCBBB\" and got \"" << a3.createString(15, 36) << "\"" << std::endl;
}
