#include <iostream>
#include <vector>

#define N 6
#define M 12

class Abacus {
public:
    std::vector <std::string> add(std::vector <std::string> original, int val) {
        int c = changeToLong(original) + val;
        std::vector <std::string> result(6, "oooooooooooo");
        changeToVector(result, c);
        return result;
    }
    int changeToLong(std::vector <std::string>& original) {
        int result = 0;
        for(int i = 0; i < N; ++i)  {
            result *= 10;
            int pos = position(original[i]);
            result += pos;
        }
        return result;
    }
    void changeToVector(std::vector<std::string>& result, int input) {
        for(int i = 0; i < N; ++i) {
            int n = (input % 10);
            changeFromPosition(result[N-1-i], n);
            input /= 10;
        }
    }
    int position(const std::string& s) {
        for(int i = 0; i < M; ++i) {
            if (s[i] == '-') {
                return 9 - i;
            }
        }
        return 0;
    }
    void changeFromPosition(std::string& result, int pos) {
        // 0 -> 9
        // 9 -> 0
        // So, 9 - pos;
        int start = 9 - pos;
        int end = start + 3;
        for (int i = start; i < end; ++i) {
            result[i] = '-';
        }
    }
};

int main(int argc, char** argv) {
    Abacus a0;
    std::vector<std::string> input0 = {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"};
    // std::cout << a0.position("ooo---oooooo") << std::endl;
    // std::cout << a0.position("o---oooooooo") << std::endl;
    // std::cout << a0.position("---ooooooooo") << std::endl;
    // std::cout << a0.position("oooooooo---o") << std::endl;
    // std::cout << a0.position("ooooooooo---") << std::endl;
    // std::cout << a0.changeToLong(input0) << std::endl;
    // std::cout << a0.changeFromPosition(0) << std::endl;
    // std::cout << a0.changeFromPosition(3) << std::endl;
    // std::string i = "oooooooooooo";
    // a0.changeFromPosition(i, 9);
    // std::cout << i << std::endl;

    // std::vector <std::string> result(6, "oooooooooooo");
    // for(auto s : result) {
    //   std::cout << s << std::endl;
    // }
    // a0.changeToVector(result, 699984);
    // for(auto s : result) {
    //   std::cout << s << std::endl;
    // }

    for(auto s : a0.add(input0, 5)) {
      std::cout << s << std::endl;
    }
}
