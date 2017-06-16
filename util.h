#include <algorithm>

#ifndef UTIL_H_
#define UTIL_H_

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

#endif  // UTIL_H_
