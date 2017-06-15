#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

class ASeries {
public:
    int longest(std::vector<int> values) {
        std::sort(values.begin(), values.end());
        // for (auto it = values.begin(); it != values.end(); ++it) {
        //     std::cout << *it << std::endl;
        // }
        makeDiffs(values);
        makeValuesMap(values);
        // for (auto it = valuesMap.begin(); it != valuesMap.end(); ++it) {
        //     std::cout << it->first << ", " << it->second << std::endl;
        // }
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
            for (auto it2 = values.begin(); it2 != values.end(); ++it2) {
                if (it == it2) {
                    continue;
                }
                int diff = *it - *it2;
                if (diff > 0) {
                    diffs.insert(diff);
                } else {
                    diffs.insert(-diff);
                }
            }
        }
    }
    void makeValuesMap(const std::vector<int>& values) {
        valuesMap.clear();
        for (auto it = values.begin(); it != values.end(); ++it) {
            auto itM = valuesMap.find(*it);
            if (itM != valuesMap.end()) {
                valuesMap[*it] += 1;
            } else {
                valuesMap[*it] = 1;
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
