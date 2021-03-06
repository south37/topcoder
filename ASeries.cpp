#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include "util.h"

class ASeries {
public:
    int longest(std::vector<int> values) {
        std::sort(values.begin(), values.end());
        makeDiffs(values);
        // util::printVector(values);
        makeValuesMap(values);
        // util::printMap(valuesMap);
        int m = -1;

        for (auto itM = valuesMap.begin(); itM != valuesMap.end(); ++itM) {
            if (itM->second > m) {
                m = itM->second;
            }
        }

        for (auto it = diffs.begin(); it != diffs.end(); ++it) {
            if (*it == 0) {
                continue;
            }

            for (auto itV = values.begin(); itV != values.end(); ++itV) {
                int i = 1;
                int next = (*itV + *it);
                while (valuesMap.find(next) != valuesMap.end()) {
                    next += *it;
                    ++i;
                }
                if (i > m) {
                    m = i;
                }
            }
        }

        return m;
    }
    void makeDiffs(const std::vector<int>& values) {
        for (auto it = values.begin(); it != values.end(); ++it) {
            for (auto it2 = std::next(it); it2 != values.end(); ++it2) {
                int diff = *it2 - *it;  // Always equal or larger than 0.
                diffs.insert(diff);
            }
        }
    }
    void makeValuesMap(const std::vector<int>& values) {
        valuesMap.clear();
        for (auto it = values.begin(); it != values.end(); ++it) {
            auto ir = valuesMap.insert(std::make_pair(*it, 1));
            if (!ir.second) {
                ir.first->second += 1;
            }
        }
    }
    std::set<int> diffs;
    std::map<int, int> valuesMap;
};

int main(int argc, char** argv) {
    ASeries a0;
    std::vector<int> v0 = {3,8,4,5,6,2,2};
    std::cout << "5 is expected, got " << a0.longest(v0) << std::endl;

    ASeries a1;
    std::vector<int> v1 = {-1,-5,1,3};
    std::cout << "3 is expected, got " << a1.longest(v1) << std::endl;

    ASeries a2;
    std::vector<int> v2 = {-10,-20,-10,-10};
    std::cout << "3 is expected, got " << a2.longest(v2) << std::endl;
}
