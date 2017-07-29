#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TransformTheTree {
  int countCuts(vector<int> p) {
    const int n = p.size() + 1;
    vector<vector<int>> g(n);
    for (int i = 0; i < p.size(); ++i) {
      g[p[i]].push_back(i + 1);
    }

    int ans = n - 1;
    vector<int> rem(n, 2);
    for (int i = n - 1; i >= 0; --i) {
      for (int j : g[i]) {
        if (rem[i] == 0) break;
        if (rem[j] >= 1) {
          ans--;
          rem[i]--;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  TransformTheTree a;
  vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 11, 12, 11, 3, 15, 16, 15, 18, 2, 1, 21, 22, 23, 24, 25, 25, 23, 22, 29, 30, 21, 32, 32, 0, 35, 36, 37, 37, 35, 40};
  std::cout << "a0: Expected 8, Got \"" << a.countCuts(p) << "\"" << std::endl;
}
