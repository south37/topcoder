#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define DEBUG 0

class TransformTheTree {
public:
  int countCuts(vector <int> parents) {
    map<int,int> m;
    for (int num: parents) {
      auto it = m.find(num);
      if (it != m.end()) {
        it->second += 1;
      } else {
        m[num] = 1;
      }
    }

    map<int, int> groupM;
    int groupCount = 0;
    int sumCount = 0;
    for(auto it = m.begin(); it != m.end(); ++it) {
      if (DEBUG) std::cout << it->first << ": " << it->second << std::endl;

      if (it -> first == 0) {
        if (it->second >= 3) {
          groupM[it->first] = it->second;
          groupCount += 1;
          if (it->second > 3) {
            sumCount += (it->second - 3);
          }
        }
      } else {
        if (it->second >= 2) {
          groupM[it->first] = it->second + 1;  // larger by parent node.
          groupCount += 1;
          if (it->second > 2) {
            sumCount += (it->second - 2);
          }
        }
      }
    }

    int pairCount = 0;
    for (auto it = groupM.begin(); it != groupM.end(); ++it) {
      if (it->first > 0) {
        int parent = parents[it->first - 1];

        auto parentIt = groupM.find(parent);
        if (parentIt != groupM.end()) {
          if (parentIt->second > 2 && it-> second > 2) {
            pairCount += 1;
            parentIt->second -= 1;
            it->second -= 1;
          }
        }
      }
    }

    int result = groupCount + sumCount;
    if (pairCount > 0) {
      result = result - pairCount;
    }
    if (result > 0) {
      return result;
    } else {
      return 0;
    }
  }
};

int main(int argc, char** argv) {
  TransformTheTree a0;
  vector<int> bottles = {0, 0, 1, 2, 1};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles) << "\"" << std::endl;

  vector<int> bottles0 = {0, 0, 0, 0, 0, 0};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles0) << "\"" << std::endl;

  vector<int> bottles2 = {0, 0, 1, 2, 3, 4, 5, 6};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles2) << "\"" << std::endl;

  vector<int> bottles3 = {};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles3) << "\"" << std::endl;

  vector<int> bottles4 = {0, 1, 2, 3, 2, 5, 0, 7, 8, 9, 8, 11};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles4) << "\"" << std::endl;

  vector<int> bottles5 = {0, 1, 2, 0, 4, 5, 6, 4, 5, 6, 0, 11, 12};
  std::cout << "a0: Expected 20.0625, Got \"" << a0.countCuts(bottles5) << "\"" << std::endl;

  // Missed
  vector<int> bottles6 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 11, 12, 11, 3, 15, 16, 15, 18, 2, 1, 21, 22, 23, 24, 25, 25, 23, 22, 29, 30, 21, 32, 32, 0, 35, 36, 37, 37, 35, 40};
  std::cout << "a: Expected 8, Got \"" << a0.countCuts(bottles6) << "\"" << std::endl;
}
