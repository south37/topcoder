#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

class ABBADiv1 {
public:
    std::string canObtain(std::string initial, std::string target) {
        auto it = memo.find(initial);
        if (it != memo.end()) { return it->second; }
        ++counter;

        if (initial == target) {
            memo[initial] = "Possible";
            return "Possible";
        }
        if (target.length() <= initial.length()) {
            memo[initial] = "Impossible";
            return "Impossible";
        }
        std::string patternA(initial);
        addA(patternA);
        if (canObtain(patternA, target) == "Possible") {
            memo[patternA] = "Possible";
            return "Possible";
        }
        memo[patternA] = "Impossible";

        std::string patternB(initial);
        addBAndRevese(patternB);
        if (canObtain(patternB, target) == "Possible") {
            memo[patternB] = "Possible";
            return "Possible";
        }
        memo[patternB] = "Impossible";

        memo[initial] = "Impossible";
        return "Impossible";
    }
    void addA(std::string& result) {
        result += "A";
    }
    void addBAndRevese(std::string& result) {
        result += "B";
        std::reverse(result.begin(), result.end());
    }
    std::size_t counter;
private:
    std::unordered_map<std::string, std::string> memo;
};


int main(int argc, char** argv) {
  ABBADiv1 a;
  std::cout << "Possible is expected, got " << a.canObtain("A", "BABA") << std::endl;
  std::cout << a.counter << std::endl;

  ABBADiv1 b;
  std::cout << "Impossible is expected, got " << b.canObtain("A", "ABBA") << std::endl;
  std::cout << b.counter << std::endl;

  ABBADiv1 b2;
  auto start = std::chrono::system_clock::now();
  std::cout << "Possible is expected, got " << b2.canObtain("A", "BABAAAAAAAAAAAAAAAAAAA") << std::endl;
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = end-start;
  std::cout << b2.counter << std::endl;
  std::cout << "Time is " << diff.count() << std::endl;

  ABBADiv1 c;
  std::cout << "Possible is expected, got " << c.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << std::endl;

  ABBADiv1 d;
  std::cout << "Impossible is expected, got " << d.canObtain("AAABAAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") << std::endl;
}
