#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 0

class TransformTheTree {
public:
  int countCuts(vector <int> parents) {
    int n = parents.size() + 1;
    vector<int> childCounts(n, 0);
    for (int num: parents) {
      childCounts[num] += 1;
    }

    vector<int> nodeCounts(n);
    int groupCount = 0;
    int sumCount = 0;
    for(int i = 0; i < n; ++i) {
      if (DEBUG && childCounts[i] >= 2) std::cout << i << ": " << childCounts[i] << std::endl;

      if (i == 0) {
        nodeCounts[i] = childCounts[i];

        if (childCounts[i] >= 3) {
          groupCount += 1;
          if (childCounts[i] > 3) {
            sumCount += (childCounts[i] - 3);
          }
        }
      } else {
        nodeCounts[i] = childCounts[i] + 1;  // larger by parent node.

        if (childCounts[i] >= 2) {
          groupCount += 1;
          if (childCounts[i] > 2) {
            sumCount += (childCounts[i] - 2);
          }
        }
      }
    }
    if (DEBUG) cout << "groupCount + sumCount: " << groupCount + sumCount << endl;

    int pairCount = 0;
    // Check starts from bottom.
    for (int i = n - 1; i > 0; --i) {  // Skip 0
      if (nodeCounts[i] <= 2) continue;
      int parent = parents[i - 1];
      if (nodeCounts[parent] <= 2) continue;

      pairCount += 1;
      nodeCounts[i] -= 1;
      nodeCounts[parent] -= 1;
    }
    if (DEBUG) cout << "pairCount: " << pairCount << endl;

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

  // Missed at contest
  vector<int> bottles6 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 11, 12, 11, 3, 15, 16, 15, 18, 2, 1, 21, 22, 23, 24, 25, 25, 23, 22, 29, 30, 21, 32, 32, 0, 35, 36, 37, 37, 35, 40};
  std::cout << "a: Expected 8, Got \"" << a0.countCuts(bottles6) << "\"" << std::endl;
}
