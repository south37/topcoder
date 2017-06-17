#include <algorithm>
#include <iostream>
#include <vector>
#include <locale>
#include <set>

class Aaagmnrs {
public:
    std::vector <std::string> anagrams(std::vector <std::string> phrases) {
        std::vector < std::string > result;
        for(auto &s : phrases) {
            std::string original = s;
            normalize(s);
            if (set.find(s) == set.end()) {
                set.insert(s);
                result.push_back(original);
            }
        }
        return result;
    }
    void normalize(std::string &s) {
        int size = s.size();
        for(int i = 0; i < size; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
              s[i] = tolower(s[i]);
            }
        }
        std::sort(s.begin(), s.end(), std::greater<char>());
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    }
    std::set< std::string > set;
};

int main(int arc, char** argv) {
    Aaagmnrs a0;
    std::vector <std::string> phrases0 = { "Aaagmnrs", "TopCoder", "anagrams", "Drop Cote" };
    for (auto const &s : a0.anagrams(phrases0)) {
        std::cout << s << std::endl;
    }
}
