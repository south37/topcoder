#include <algorithm>

namespace util {

void printVector(std::vector<int> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void printMap(std::map<int, int> m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
    }
}

}
